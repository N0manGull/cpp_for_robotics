// Coding: Implement bubble sort on an integer array
// have to optimize further. 

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){ 
    // O(n^2) time complexity of bubble sort is n square which is not a good time complexity 
    // we prefer nlogn time complexity 
    for(int i =0; i<n-1; i++){ // 1 * n
        bool isSwap = false;
        for (int j=0; j<n-i-1; j++){ // n * n
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){ // array is already sorted,
            // by this optimization we can improve time complexity of this code  
            return;
        }
    } 
}


void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    }




int main(){
    int n = 5;
    int arr [] = {9,43,11,9,6};

    bubbleSort(arr, n);
    printArray(arr, n);


    return 0;
}