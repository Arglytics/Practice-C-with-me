#include <iostream>
#include <cmath>
using namespace std;

//#include <cmath>
/*
using namespace std;
int f_of_x(double x)
{                      
double f;
f = 3.0*x*x+1.0;
return f;
}
*/


int main() 
{

double x;
double f;

for(x=-10; x<=10; x =x+0.5)
{
f = 3.0*x*x+1.0;
cout << "x= " << x << endl;
cout << "f= " << f << endl;

//return f;
}

return 0;
}
