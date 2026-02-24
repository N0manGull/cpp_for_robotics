// if/else: 
// using if/else syntax we can write conditional statements which creates logic to
// make descision in a programme.  

#include <iostream>
using namespace std;

int main(){
    char ch;
    cout << "Enter character to check lower and upper case:";
    cin >> ch;
    
    if(ch >= 'a' && ch <= 'z'){
        cout << "Lower case character." << endl; 
// we can check this only because of implicit character conversion using ASCII code.
    }
    else{
        cout << "Upper case character." << endl;
    }
    
// we can also write code of if/else using if/else ternary statements:    
    int n = -45;
    cout << (n >= 0 ? "True" : "False") << endl;
 // but we usually don't prefer them because of readability issue of code.
    
// Switch:
// Just like if/else statements for descision making in code we can also write 
// same code using switch statement syntax to execute our descision 
// it is usually used to execute all code either any statement is true of false

 switch (ch){
        case 'f':
            cout << "Your entered character is f" << endl;
            break;
        case 'c':
            cout << "Your entered character is c" << endl;
            break;
        case 'o':
            cout << "Your entered character is o" << endl;
            break;
        case 'a':
            cout << "Your entered character is a" << endl;
            break;
        case 'z':
            cout << "Your entered character is z" << endl;
            break;
        default:
            cout << "You entered upper case character" << endl;   
    }
 return 0;
}

    
