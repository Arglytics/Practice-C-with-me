#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
cout << "argc = " << argc << endl;
cout << "argv = " << argv << endl;

if (argc < 3)
{
cout << "not enough arguments" << endl;
cout << "try with " << endl;
cout << "read_argumets.ext <int num_of_it> <string filename>" << endl;
return 0;
}

int first_argument;
first_argument = atoi ( argv[1] );
cout << "first_argument = " << first_argument << endl;

string second_argument;
second_argument = argv[2];
cout << "second_argument = " << second_argument << endl;


return 0;
}
