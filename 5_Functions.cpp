// Function:
// If we want to do some work again and again, so we write
// that work in the form of function.
// e.g:
// functionType printHello(){
//     cout << "Hello";

// }

// Functions in Memory:
// there are two types of memory stack (used for static allocation) 
// and heep (used for dynamic allocation)
// 1. every function is stored in the stack memory in the form of frame.
// 2. the variables in the functions also store in the main stack memory called call stack
// 3. after execution the value of function will be returned to the main memory stack 
// and will be no longer available to call outside of the function. 

//since return statement is the last statement of the function 
// so after return 0; of the main function the stack memory will be cleared.
// we can also use return statement like this:
// void fun(){
//     if(condition){

//     }
//     else if(){
//         return; // this represent the control which shows where we are in the program.
//     } // if condition true the return will give output by terminating program.      
// }


#include <iostream>
using namespace std;

// function definition:
int printHello(){
    cout << "hello\n"; 
    return 3; // it will return 3 after execution. 
}

// function for sum:
int sum(int n){ // here int n is the parameters 
    int s; 
    for(int i = 0; i<=n; i++){
        s = i + n;
    }
    return s;
}

// Binomial coefficient function for equaiton:
// Here you see how a function can use another function.
int factorial (int n){
    int fact = 1;
    for (int i = 1; i<=n; i++){
        fact * i;
    }
    return fact;
} 

int nCr(int n, int r){
    int fact_n = factorial(n);
    int fact_r = factorial(r);
    int fact_n_minus_r = factorial(n-r);

    return fact_n / (fact_r * fact_n_minus_r);

}


int main(){
    cout << printHello() << endl; // calling function to print.
    int val = printHello(); // we can also store return value of a function.
    cout << "val = " << val << endl;
    cout << sum(67) << endl; // here 67 is the argument/literal. 
    int n = 6, r = 3; // calling by reference
    cout << nCr(n,r) << endl;
    return 0;
}

