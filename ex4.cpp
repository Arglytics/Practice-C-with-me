// calculating potential,total energy and interaction forces of atomic system.

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>

using namespace std;

int main(int argc, char *argv[])
{
 if (argc !=2)
{
cout << "argc = " << " wrong invocation! please, try with:" << endl;
cout << "argc = " << " ./graphene.exe<double sigma > < nx> <double epsilon > <string xyz_file> <string output_file> " << endl;

return 0;
//exit(0);
}

int r_i;
int r_j;
double sigma,epsilon;
string xyz_file;
string output_file;

sigma=atoi(argv[1]);
epsilon=atoi(argv[2]);
xyz_file = argv[3];
output_file = argv[4];

cout  << " xyz_file " << xyz_file  << endl;
cout  << " output_file " << output_file << endl;

ifstream xyz_file;
xyz_file.open(xyz_file_name.c_str());

if (xyz_file.is_open() == 0 )
{

cout << "error: could not locate specified xyz file!" << endl;
exit(1);

} 

int number_of_atoms;

	string line;
	istringstream iss;
	
	getline(xyz_file, line);
	cout << "line = " << line << endl;
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
	
	getline(xyz_file, line);
	cout << "line = " << line << endl;
	
	for (int i = 0; i < number_of_atoms; i++)
	{		
		getline(xyz_file, line);
		
		if ( line.length() == 0 )
		{
			cout << "error: empty line encounered!" << endl;
			exit(4);
		}
		
		if ( xyz_file.eof() == 1 )
		{
			cout << "error: end of file reached too early!" << endl;
			exit(3);
		}
		
		cout << "line = " << line << endl;
		
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
		
		cout << "atom i = " << i << " name = " << element_names[i]
		     << " coords = " << coordinates[i][0] << ", "
		                     << coordinates[i][1] << ", "
		                     << coordinates[i][2] << endl;
	}
	
	xyz_file.close();
	
	return 0;
}

for ()
{

postion = 0;
velocity=0;

float velocity,potential,force;
velocity = (r_j - r_i)
potential = 4*epsilon[pow(sigma/r_i,12)-pow(sigma/r_j,6)]
force = 24*epsilon[2(pow(sigma/r_i,12)-pow(sigma/r_j,6))]



