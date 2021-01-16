#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cmath>

using namespace std;
#include <time.h>



int main(int argc, char *argv[])
{

if ( argc != 5 )
{
	cout << "wrong invocation! please, try with:" << endl;
	cout << "  read_xyz.exe <input_file.xyz> <output_file.xyz> <epsilon> <sigma>" << endl;
	return 0;
}
  //Parameters
  ofstream output_file;
  ifstream input_file;
  istringstream iss;

  int number_of_atoms;
  double epsilon;
  double sigma;
  
  string output_file_xyz;
  string input_file_xyz;
  string line;
  
 //Commandline inputs
  input_file_xyz = argv[1];
  output_file_xyz = argv[2];
  epsilon = atof(argv[3]);
  sigma = atof(argv[4]);
  
  
 // Open the input and output files
  input_file.open(input_file_xyz.c_str());
  output_file.open(output_file_xyz.c_str());
  
  cout << "epsilon = " << epsilon << endl;
  cout << "sigma = " << sigma << endl;
  cout << "input file = " << input_file_xyz << endl;
  cout << "output file = " << output_file_xyz << endl;

  
  	
	
	
	cout << "input_file_xyz = " << input_file_xyz << endl;
	
	if ( input_file.is_open() == 0 )
	{
		cout << "error: could not locate specified xyz file!" << endl;
		exit(1);
	}
	
	getline(input_file, line);
	//cout << "line = " << line << endl;
	iss.str(line);
	iss >> number_of_atoms;
	cout << "number_of_atoms = " << number_of_atoms << endl;
	
	if ( number_of_atoms < 1 )
	{
		cout << "error: incorrect xyz file (non-positive number of atoms)!" << endl;
		exit(2);
	}
	
	string element_names[number_of_atoms];
	double coordinates[number_of_atoms][3];
	
	getline(input_file, line);
	//cout << "line = " << line << endl;
	
	
	for (int i = 0; i < number_of_atoms; i++)
	{		
		getline(input_file, line);
		
		if ( line.length() == 0 )
		{
			cout << "error: empty line encounered!" << endl;
			exit(4);
		}
		
		if ( input_file.eof() == 1 )
		{
			cout << "error: end of file reached too early!" << endl;
			exit(3);
		}
		
		//cout << "line = " << line << endl;
		
		iss.clear();
		iss.str(line);
		iss >> element_names[i];
		iss >> coordinates[i][0];
		iss >> coordinates[i][1];
		iss >> coordinates[i][2];
		
		if ( ( coordinates[i][0] != coordinates[i][0] ) ||
		     ( coordinates[i][1] != coordinates[i][1] ) ||
		     ( coordinates[i][2] != coordinates[i][2] ) )
		{
			cout << "error: NaN value encountered!" << endl;
			exit(5);
		}
	}
    // potential & forcei_j formular
  double potential[number_of_atoms];
  double forcei_j[number_of_atoms][3];
  double dist_i_j[3];
  double distance_square;
  double d;
  double d6;
  double d12;
  clock_t tStart = clock();
  for (int i=0; i< number_of_atoms; i++)
  {
    potential[i] = 0;
    forcei_j[i][0] = 0;
    forcei_j[i][1] = 0;      
    forcei_j[i][2] = 0;
      
    
    for (int j=0; j< number_of_atoms; j++)
    {
      if (i == j)
      {
      	continue;
      }
		dist_i_j[0] = coordinates[j][0] - coordinates[i][0];
		dist_i_j[1] = coordinates[j][1] - coordinates[i][1];
		dist_i_j[2] = coordinates[j][2] - coordinates[i][2];
			
		distance_square =(dist_i_j[0]*dist_i_j[0] + dist_i_j[1]*dist_i_j[1] + dist_i_j[2]*dist_i_j[2]);

		
		d = (sigma*sigma)/(distance_square);
		d6 = d*d*d;
		d12 = d6*d6;

		potential[i] = potential[i] + 0.5*4*epsilon*(d12 - d6);
		forcei_j[i][0] = forcei_j[i][0] + 24*epsilon*(1/distance_square)*(d6- 2*d12)*dist_i_j[0];
		forcei_j[i][1] = forcei_j[i][1] + 24*epsilon*(1/distance_square)*(d6- 2*d12)*dist_i_j[1];
		forcei_j[i][2] = forcei_j[i][2] + 24*epsilon*(1/distance_square)*(d6- 2*d12)*dist_i_j[2];
    }
    //save to output file
	output_file << forcei_j[i][0] << "  " << forcei_j[i][1] << "  " << forcei_j[i][2] << "  " << potential[i] << endl;
  }
cout << "Time: " << (double)(clock() - tStart) << endl;


	input_file.close();
	output_file.close();
	return 1;
}
