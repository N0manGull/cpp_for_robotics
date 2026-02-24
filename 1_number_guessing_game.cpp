#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a guess number between 1 and 10: ";
    cin >> n;
    
    if (n < 5){
        cout << "It's Too Low!" << endl;
    }
    else if (n == 5){
        cout << "Correct Guess" << endl;
    }
    else{
        cout << "It's Too High" << endl;
    }

    return 0;
}