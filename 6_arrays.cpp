// data structures are basically structre in our code,
// which are used to store data.
// e.g:  linear, hiararchial, etc.
// Operations perform on our data are called algorithm. 
// Arrays: It is a data structure, which is use to store
// large amount of data. It is like block of data.
// Arrays are contiguous in memory, linear, 
// use: when we have to store hundreads or million of data we use 
// array instead of making seperate variable for each and every object.



#include<iostream>
#include<climits>
using namespace std;

int main(){
    int size = 5; // size initialization for an array.
    int marks[size] =  {99, 100, 54, 36, 88}; // the size of any array is from 0 to size -1.
    // we dont have to specify arrays range if we already assign it with list.
    double price[] = {98, 99, 105.67, 30.00};

    cout << marks[0] << endl;
    cout << marks[1] << endl;
    cout << marks[2] << endl;
    cout << marks[3] << endl;
    cout << marks[4] << endl;
    marks[0] = 45; // this will replace the value from the array.
    cout << marks[0] << endl;
    // cout << marks[-1,7];  is out of the range and may lead to garbage values.
    cout << sizeof(marks) << endl; // will show the size of marks.
    
    // generally we use loops to perform operations or to get output of whole values in arrays.
    for (int i=0; i < size; i++){
        cout << marks[i] << " " << endl; 
    }
    
    // Loops on arrays:
    // we can also take the input values to save as an array:
    int Size = 3;
    int values [Size];
    cout << "Enter your values to be saved as an array: ";
    for (int i=0; i<Size; i++){
        cin >> values[i];
    }
    for (int i = 0; i < Size; i++){
        cout << values[i] << endl;
    } 
    
    // To find smallest value from an array we use: __INT_MAX__ (known as +infinity)
    // To find largest value from an array we use: __INT_MIN__ (known as -infinity)
    // we have to write #include <climits> to include library
    
    int smallest = INT_MAX;
    int smallest_index = 0;
    int largest = INT_MIN;
    int largest_index;
    for (int i=0; i<Size; i++){
        if (values[i]<smallest){ 
            smallest = values[i];
            smallest_index = i;
        }
    }
    for (int i=0; i<Size; i++){
        if (values[i]>largest){ 
            largest = values[i];
            largest_index = i;
        }
    }
    cout << "Smallest value: " << smallest << "\nIts index no is " << smallest_index << endl;
    cout << "Largest value: " << largest << "\nIts index no is " << largest_index << endl;
    
    return 0;
}