#include<iostream>
using namespace std;

int main(){
    int n = 0, m;
    cout << "Welcome to Number Guessing Game." << endl; 
    cout << "You have 3 chance to win. Good luck!" << endl;
    bool guess = false;
    while(n<3){
    cout << "Attempts left: " << 3 - n << endl;
    cout << "Enter a guess number between 1 and 10: ";
    cin >> m;
        
    if (m < 5){
        cout << "It's Too Low!" << endl;
    }
    else if (m == 5){
        cout << "Correct Guess" << endl;
        guess = true;
        break; 
    }
    else{
        cout << "It's Too High" << endl;
    }
    n++;
    }
    if(guess == true){
        cout << "Well Played." << endl;
    }
    else{
        cout << "Game Over! Better luck next time." << endl;
    } 
    return 0;
}