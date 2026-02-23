// Variables: (means which can be changed)
// varaiables are the containers to store data.
// e.g: age = 25 
// rules: variables must be start with underscore or an alphabet
// it can not be start with numbers.  
// Variables are also known as identifiers. e.g: age
// but we usually use data types with variables.
// DataTypes: It assigns the type of data we want to define as variables.
// e.g: Primitive datatypes: int (4bytes), char (1 bytes), float (4 bytes), 
// bool (1 byte), double (8 bytes)
// e.g: Non Primitive datatypes: array, strings, etc. 

#include<iostream>
using namespace std;

int main(){
    char name = 'n'; // for char we use single quotes.
    string full_name = "nomangull"; // we use double quotes for string. 
    int age = 25;
    float PI = 3.14;
    bool isSafe = true;
    double price = 99.99; // double is same like float 
    
    cout << name << "\n" << sizeof(name) << endl; 
    cout << full_name << "\n" << sizeof(full_name) << endl; 
    cout << age << "\n" << sizeof(age) << endl;
    cout << PI << "\n" << sizeof(PI) << endl;
    cout << isSafe << "\n" << sizeof(isSafe) << endl; // bool only gives output in the form of 0 and 1.   
    cout << price << "\n" << sizeof(price) << endl;


    return 0;
}


