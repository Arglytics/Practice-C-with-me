#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() 
{

double x;
double f;

ofstream output_file;
output_file.open("function.txt"); //associate the ofstream with a file

for(x=-10; x<=10; x =x+0.5)

{

f = 3.0*x*x+1.0;
output_file << "x= " << x << endl;
output_file << "f= " << f << endl;

}

output_file.close(); //closing the file
return 0;
}
