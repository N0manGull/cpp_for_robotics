// arrays operations: 

#include<iostream>
#include<climits>
using namespace std;

void changeArr(int arr1[], int size){
        cout << "in function \n";
        for(int i =0; i<size; i++){
            arr1[i] = 2 * arr1[i];
        }
    }

int linearSearch(int arr2[], int size, int target){
    for (int i = 0; i <= size; i++){
        if (arr2[i]==target){ // for finging value 
            return i; 
        }
    }
    return -1; // in case value is not found. 
}

void reverseArray(int arr3[], int sz){ // both case reversing concept included either even or odd.
    int start = 0, end = sz -1;
    while (start < end){
        swap(arr3[start], arr3[end]);
        start ++;
        end --;
    }
}

 int main(){

    // In c++ a reference is an alternative name for an object or function, and its 
    // address is the address of the object or function it refers to. 
    // Here for the sake of understanding we are calling it address.  

    // Array pass by reference: By passing by reference actually we pass address to a
    // function and when ever we have address we can change it by address. 
    // it means we are doing changes in the orignal values. 
    // in case of pass by value, copies of orignal value is being created.
    
    // void function is mentioned before int main()
    int arr1[] = {1,2,3};
    changeArr(arr1,2);
    cout << "int main\n";
    for (int i = 0; i<3; i++){
        cout << arr1[i] << " "; 
    }
    cout << endl;

    // Linear Search Algorithm: Search value based on index values.
    // Its time complexity is 0(n) linear  
    int arr2[] = {4,5,7,9, 6};
    int size = 4;
    int target = 5;
    cout << linearSearch(arr2, size, target) << endl; 
    

    // Reversing an array:
    int arr3[] = {4, 2, 7, 8, 1, 2, 5};
    int sz = 7;
    
    reverseArray(arr3, sz);
    for (int i = 0; i<sz; i++){
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}