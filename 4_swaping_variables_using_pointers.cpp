// Swap two variables using pointers:

#include<iostream>
using namespace std;




void swapAB(int *a, int *b){

    swap(*a, *b);
}
int main(){
    int a = 23;
    int b = 45;
    swapAB(&a,&b);
    cout << a << endl;
    cout << b << endl;
    return 0;
}