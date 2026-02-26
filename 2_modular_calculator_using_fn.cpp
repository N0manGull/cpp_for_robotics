// Coding: Create modular calculator in C++ with separate functions.
#include<iostream>
#include<cmath>
using namespace std;

// Modular calculator functions:
// Sum:
int sum(int a, int b){
    
    return a + b;
}
// Subtraction:
int subtract(int a, int b){
    
    return a - b;
}
// Product:
int product(int a, int b){
     
    return a * b;
}
// Divide:
int divide(int a, int b){
    
    return a / b;
}
// Modulus:
int modulo(int a, int b){
    
    return a % b;

}

int main(){
    int a, b;
    char fun;
    cout << "Enter your first number: ";
    cin >> a;
    cout << "Enter your second number: ";
    cin >> b;
    cout << "Enter operation (+, -, *, /, %) to perform on given numbers: ";
    cin >> fun;
    if(fun == '+'){
        cout << "Sum of given values is: " << sum(a,b) << endl;
    }
    else if(fun == '-'){
        cout << "Subtraction of given values is: " << subtract(a,b) << endl;
    }
    else if(fun == '*'){
        cout << "Product of given values is: " << product(a,b) << endl;
    }
    else if(fun == '/'){
        if(b == 0)
            cout << "Error: Division by zero is not allowed" << endl;
        else
            cout << "Division of given values is: " << divide(a,b) << endl;
    }
    else if(fun == '%'){
        if(b == 0)
            cout << "Error: Division by zero is not allowed" << endl;
        else
            cout << "Modulo of given values is: " << modulo(a,b) << endl;
    }
    else {
        cout << "Invalid operator" << endl;
    }
    return 0;
}