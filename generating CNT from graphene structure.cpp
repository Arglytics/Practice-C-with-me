// generating CNT from graphene structure 

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>

using namespace std;

int main(int argc, char *argv[])
{
 if (argc !=6)
{
cout << "argc = " << " wrong invocation! please, try with:" << endl;
cout << "argc = " << " ./graphene.exe<float a> <int nx> <int ny> <string el_name> <string file_name> " << endl;

return 0;
//exit(0);
}

float a;
int nx;
int ny;
string el_name;
string file_name;

a = atof(argv[1]);
nx=atoi(argv[2]);
ny=atoi(argv[3]);
el_name = argv[4];
file_name = argv[5];

cout  << " run parameters " << endl;
cout  << " a= " << a << endl;
cout  << " nx= " << nx << endl;
cout  << " ny= " << ny << endl;
cout  << " el_name " <<  el_name << endl;
cout  << " file name " << file_name << endl;

int predicted_number_of_atoms;
predicted_number_of_atoms = 4*nx*ny;
double pi=3.141593;
//double length_y=1.732*a*ny;
double radius=(sqrt(3)*a*ny)/(2*pi);
double alpha;

double coords[predicted_number_of_atoms][4];
int current_number_of_atoms = 0;

for (int i=0; i<nx; i++)
{
 for(int j=0; j<ny; j++)
{
 
//atom 1=a,0,0     
coords[current_number_of_atoms][0] = (i*3*a) + a;
coords[current_number_of_atoms][1] = j*sqrt(3)*a;
alpha = coords[current_number_of_atoms][1]/radius;
coords[current_number_of_atoms][2] = radius*cos(alpha);
coords[current_number_of_atoms][3] = radius*sin(alpha);
current_number_of_atoms++;

//atom 2 = 2a.0.0
coords[current_number_of_atoms][0] = (i*3*a) + (2*a);
coords[current_number_of_atoms][1] = j*sqrt(3)*a;
alpha = coords[current_number_of_atoms][1]/radius;
coords[current_number_of_atoms][2] = radius*cos(alpha);
coords[current_number_of_atoms][3] = radius*sin(alpha);
current_number_of_atoms++;

//atom 3 = 0.5dcc,0.866a,0
coords[current_number_of_atoms][0] = (i*3*a)+(a/2);
coords[current_number_of_atoms][1] = (j*sqrt(3)*a) + (sqrt(3)*a/2);
alpha = coords[current_number_of_atoms][1]/radius;
coords[current_number_of_atoms][2] = radius*cos(alpha);
coords[current_number_of_atoms][3] = radius*sin(alpha);
current_number_of_atoms++;

//atom 4 = 2.5a,0.866a,0
coords[current_number_of_atoms][0] = (i*3*a) + (a*5/2);
coords[current_number_of_atoms][1] =  (j*sqrt(3)*a)+ (sqrt(3)*a/2);
alpha = coords[current_number_of_atoms][1]/radius;
coords[current_number_of_atoms][2] = radius*cos(alpha);
coords[current_number_of_atoms][3] = radius*sin(alpha);
current_number_of_atoms++;
}
}

ofstream xyz_file;
xyz_file.open(file_name.c_str());

//if (xyz_file.is_open() == 0)
//{
//cout << "error: could not create xyz file!" << endl;
//exit(0);

//}

xyz_file << current_number_of_atoms;
xyz_file << endl << endl;
	
	for (int i = 0; i < current_number_of_atoms; i++)
	{
		xyz_file << el_name << "   " << coords[i][0] << "   " << coords[i][2] << "   " << coords[i][3] << endl;
	}
	
	xyz_file.close();

return 0;
}



