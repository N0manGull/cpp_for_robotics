// Loops: When ever we have to write a program to execute multiple statements
// agian and again we usually write loops. 
// e.g: while loop, for loop and do while loop
// Desclaimer: Do not write infinite loops, it can full memory of system and sometimes
// application may crash, just because there is not ending point of these loops and 
// will execute infinitly.
// Extras: It is good programming practice to write meaningful variables we usually
// use camelCase like totalSum, fixedPrice,etc but in loops we prefer meaningless variables 
// like i, j, k etc for our convinience. 
// "break;" key word can be used to break the execution of the code


#include <iostream>
#include<cmath>
using namespace std;

int main(){
    // While loop:
    int count = 1;
    while (count <= 5){
        cout << count << endl;
        count++;
    }
    
    // for loop: 
    // for (initialization, condition, updation){ 
    // work }        1. check condition,  2. work,  3. update,  
    // 4.check condition again if true, 5. works again,  if false end the program. 

    for(int i = 1; i<=5; i++){
        cout << i << endl;
    }

    // to execute sum from sequence of numbers:
    int sum = 0;
    for (int i = 1; i<= 4; i++){
        sum += i;
        cout << sum << endl;
    }

    // to print the odd numbers:
    cout << "Odd numbers from the loop are: " << endl;
    for (int i=0; i<=10; i++){
        if (i%2 != 0){
            cout  << i << endl;
        }
    }

    // Simple approach to check Prime numbers:
    int n;
    bool isPrime = true;
    cout << "Enter any number to check either it is prime or not: ";
    cin >> n;    

    for (int i = 2; i*i < n - 1; i++){ 
        // basically at some point during multiplication the value of any greater number
        // repeat like 1 x 25 or 5 x 5 or 25 x 1 so for i < n we can check this condition
        // before multiply each number again and again we can simply use i < sqrt(n) or i*i < n 
        // this will reduce the execution time and solve the problem early.   
        if (n%i == 0){
            isPrime = false;
            break;
        }
    }
    if(isPrime == true){
        cout << "Prime Num";
    }
    else{
        cout << "Not a Prime Num";
    }

    cout << "\n \n";
    // do while loop:
    // if we write a while loop if its condition becomes false it will never execute
    // but if we use do while loop it will execute the code first then  the condition 
    // will execute at the end of the code.   
    int i = 0;
    do{
        cout << i << " ";
        i++;
    }
    while(i<= 10);
        
    cout << endl;

    // Nested loop: loop in which we used to use sub loops for multiple iteration.
    int s = 10;
    for (int i = 1; i<=s; i++){
        int m = 5;
        for (int j=1; j<=m; j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

