// Operators: 
// Operators are used to perform operations.
// Types of operators: 
// Arithmatic operators used to perform calculations (+, -, *, /, %)
// Relational operators used to compare values (==, !=, <, >, <=, >=)
// Logical Operators used to (||, &&, !)
// Binary Operators perform operations using two values like arithmatic operators
// Unary Operators perform operations using single value only (++, --) 


#include<iostream>
using namespace std;

int main(){
    int a, b, c, d, e, f, g;
    double h = 45.902;

    cout << "Enter value for first interger:";
    cin >> a;

    cout << "Enter value for second interger:";
    cin >> b;
    
    // Arithmetic operators:
    c = a + b;
    cout << "Sum of given values is: " << c << endl; 
    d = a - b;
    cout << "Difference of given values is: " << d << endl;
    e = a * b;
    cout << "Product of given values is: " << e << endl;
    f = a / b;
    cout << "Division of given values is: " << f << endl;
    // if we divide like int/float or int/double or float/int or doubole/int this 
    // will give the output in greater data type like float or double
    // also can typecast if we want to change the type of output like:
    cout << "Typecasted value: " << (b / (double)h) << endl;
    g = a % b;
    cout << "Modulo of given values is: " << g << endl;

    // Relational Operators:
    cout << (a<b) << endl; // Gives output in bool datatype
    cout << (a>b) << endl;

    // Logical Operators:
    cout << ((1<4) || (2<1)) << endl; // Gives output in bool datatype
    cout << ((1<4) && (2<1)) << endl;
    cout << !(1<4) << endl; 

    // Unary Operators:
    cout << "Pre-increment " << (++a) << endl << "Post-increment " << (a++) << endl;
    cout << "Pre-decrement " << (--a) << endl << "Post-decrement " << (a--) << endl;

    return 0;
}