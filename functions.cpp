#include <iostream>

using namespace std;
//defining the function before the main fn inorder to be recognised by the compiler.

int maximum(int x, int y) //dclaring function
{               //body of function.

if (x>y)        //activity of function.
return x;
else
return y;
}

//main function
int main()
{
int a,b;
cout << "enter 2 numbers to find the greatest: " << endl;
cin >> a >> b; //we need to provide a and b.
int c = maximum(a,b);
cout << "greatest value is: " << c << endl;
return 0;
}
