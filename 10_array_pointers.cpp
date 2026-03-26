#include <iostream>
using namespace std;

int main(){
    // Array Pointers (constant pointer):
    // An array the name arr is a pointer itself with its own address in c++
    // actually arr is a special variable which is a pointer in c++ 
    // it always points the zeroth index of our array
    
    int arr[] = {6,2,3,4,5};
    
    int a = 15;
    int b = 10;
    // arr = &a; // constant pointer can not be changed thats why showing error

    cout << arr << endl; // arr act as an array gives the output of the zeroth index address
    cout << *arr << endl; // *arr gives the output of the zeroth index value
    
    // Pointer Arithmetic:
    // Increment (++):
    // It works like if the end of the address is 48 if 8 bytes are going to increase
    // then 49 (1 byte), 4a (2 byte), 4b (3 byte), 4c (4 byte), 4d (5 byte), 4e (6 byte), 4f (7 byte) and  50 (8 byte),
    int *ptr = &a;

    cout << ptr << endl;
    ptr++; // will increment in address memory based on the data type 
    cout << ptr << endl; // in this case it is int therefore increase +4 bytes in address memory.


    // Decrement (--):
    int *ptr2 = &b;

    cout << ptr2 << endl; 
    ptr2--; // will increment in address memory based on the data type
    cout << ptr2 << endl; // in this case it is int therefore increase +4 bytes in address memory.
    
    // Addition:
    ptr = ptr + 2; // will add 2 integers value (8 bytes) in the address memory.
    
    cout << ptr << endl;

    // Subtraction:
    ptr = ptr2 - 2; // will subtract 2 integers value (8 bytes) in the address memory.
    
    cout << ptr2 << endl;

    // Now by using addition and subtraction concept for memory address we can access array's stored variable
    // by order which is stored in an array according to data type like:
    cout << * arr << endl; 
    cout << * (arr + 1) << endl; // using dereference operator to access value 
    // and + value to increase or decrease the number of bytes in it.
    cout << * (arr + 2) << endl; // gives the next value as our value is in the form of intergers 
    // therefore by increasing 4 bytes each time gives the next number stored in array.
    
    // Subtraction of pointers:
    // in c++ it is not allowed to add two pointers but we can subtract it 
    // and will get the output of the gap of datatype in between them like: 

    int ptr3 = 23;
    int ptr4 = ptr3 + 2; // will add 8 bytes to ptr3 and store it to the variable ptr4

    cout << ptr4 - ptr3 << endl; // will give the output of the value of 2 
    // which is same size of memory stored in it in bytes. 

    // Comprison of pointers (< , > , ==, <=, >=, !=):
    // We can compare either any pointer is greater or lesser. 
    cout << (ptr4 < ptr3) << endl; // will give answer in 1 and 0 which is yes or no


    return 0;
}