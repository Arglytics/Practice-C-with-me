#include <iostream>

using namespace std;

int main()
{
int number_cats = 4;
int number_dogs = 5;
cout << "number of cats=" << number_cats << endl;
cout << "number of dogs=" << number_dogs << endl;
cout << "total animals=" << number_cats + number_dogs << endl;
//Re-assigning a new value to a variable.
//cout << "new number of dogs=" << endl;
number_dogs = number_dogs + 1;
cout << "new number of dogs=" << number_dogs << endl;

return 0;
}
