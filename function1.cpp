#include<iostream>
#include<cmath>

using namespace std;

double f_of_x(double x)  //declaring the function,name of fn,parameter list in the brackets.
{
double f;
f = 3.0*x*x+1.0;
return f;
}


int main()
{
int a;
cout << "enter a" << endl;
cin >> a;
double f_of_b;
f_of_b = f_of_x(a);
cout << f_of_b << endl;
return 0;
}
