#include <iostream>
using namespace std;

void changeB(int*ptr3){ // pass by reference using pointers
    *ptr3 = 20; // will change the value of the address linked to to b
}

void changeC(int &c){ // pass by reference using alias
    c = 20; // will change the value of the address linked to to b
}

int main(){
    // Memory Addresses: 
    // & ampersand operator is used to allocate the address of a value/variable.
    // Gives a number like: 0x(Hexadecimal number)

    // Pointers:
    // special variable that store address of other variables.  
    // when ever we use * with a variable we are using pointer.

    int a = 10; // can also use the same concept with floating values
    
    int *ptr = &a;

    // Pointer to pointer:
    // we can also create a pointer which can store another pointer's value. 

    int **parentptr = &ptr; // to store value of a pointer in another pointer. 

    cout << &a << endl; // here we have same addresses of &a and ptr because ptr saves the address value of &a.
    cout << ptr << endl;
    cout << &ptr << endl; // but in case of &ptr, it shows different address due to its own seperate address.
    cout << parentptr << endl;
    cout << &parentptr << endl;
    
    // Dereference operator (*): 
    // To find the value at an address stored in a variable we use dereference operator

    cout << *&a << endl; // dereference operator, it will show the value stored in a pointer
    cout << *(ptr) << endl;
    cout << *(&parentptr) << endl; // it will show the value stored in other pointer 
    // which is the address of other value therefore results in the form of its address.  
    cout << **(parentptr) << endl; // to decode the value stored in anohter pointer's address, use double dereference operator here.

    // Null Pointer:
    // A pointer that does not point to any location.
    // int * ptr = NULL; 

    int *ptr2 = NULL;

    cout << ptr2 << endl; // output value of null pointer
    // cout << *ptr2 << endl; // we can not dereference a null pointer because it is not pointing a valid pointer address.
    // and will give the output as an error.

    // Pass by reference:
    // There are two methods of pass by reference
    
    // 1. by using pointers (* variable): 
    // When ever we want to change a value by passing it through a parameter we used to use two methods
    // either pass by value like a = 10; and we declare it as b = 20, a = b then print a will gives us a as 20
    // but in case of pass by reference we use pointer address to change it.

    int b = 40;

    changeB(&b); // it will pass the address to the pointer *ptr
    
    
    cout << "Inside the function " << b << endl;
    
    // 2. by using references (alias) (& variable)
    // In case of alias we use & sign to make two values of same address and 
    // by changing one of them reflect the change in another value.

    int d = 30; 

    changeC(d); // it will pass the address to the pointer *ptr
     
    cout << "Inside the function " << d << endl;
    
    return 0;
}




