// Generally string can be letter or sentence enclosed in double quotes.
// In case of simple character array we normally use, 
// char str[] = {8,3,4,6,2,6}; but,

// character arrays (cstring): we use specially '\0'
// like:
// char str[] = {'a', 'b', 'c', '\0'}; here \0 contains 1 byte of memory like normal char value. 


#include<iostream>
#include<cstring>
#include<limits>
#include <algorithm>

using namespace std;

int main(){
    
    char str[] = {'a','b','c','\0'};
    int arr[] = {1,2,3};
    char str2[] = "hello"; // string literals, it creates array of this string 
    //and we can also access individual characters using indexing and last character is of \0

    cout << str << endl; // constant pointers, and give output in clubed form like a single string
    cout << strlen(str) << endl;
    cout << strlen(str2) << endl;
    cout << str2[3] << endl;
    cout << arr << endl; // will give memory address

    // char str3[10];
    // cout << "enter char array: ";
    // cin >> str3; // when you enter a sentence you will see only 1st word is being printed
    // // but it will ignore remaining sentence after space. In this case we will use special function:
    // cout << "Output: " << str3 << endl;

    // char str4[12];
    // cout << "you can enter full sentence:"; 
    // cin.getline(str4, 12, '$'); // (str, len, delim?) str is for character name, 10 is for its length 
    // // and delim? is an optional parameter called delimiter,
    // // it is used, when you want to stop taking input after a specific character. like $  
    // cout << "Output: " << str4 << endl;

    // when we want to take output for the character array it is very similar to integer array by applying loops
    // for(char ch : str4){ // for each loop 
    //     cout << ch << " "; // if you don't set limit to the characters it will include garbage value to complete limit
    // }
    // cout << endl;
    
    // // we can also use loop to get output for lenght of the sentence. You can also use strlen(str) for it. 
    // int len = 0;
    // for (int i=0; str4[i]!='\0';i++){ // for each loop 
    //     len ++;
    // }
    // cout << "Length of string " << len << endl;

    // In C++ we have a class name as string which is used to make objects in program. 
    // like we have int for integer, char for character, similarly we have string for strings
    // these strings are different from character strings and actually advance versions of strings. 
    // in this case we have to include a library called #include <cstring>
    string str5 = "Hello world"; // these dynamic in nature 
    cout << str5 << endl;

    str5 = "not hello"; // this is not possible to do in character array (c string) which is easy here
    cout << str5 << endl; 

    // like:
    // char chArr[] = "My name is noman"; // this is fixed and can not be changed after it 
    // chArr = "Hello";  // and when we assign it with other value it will show error. 
    
    // we can also do concatination with simple string like:
    string str6 = "Noman";
    string str7 = "Gull";
    string str8 = str6 + str7; // concatination
    cout << str8 << endl;
    cout << (str6 == str7) << endl; // can also check either both string's value are equal or not.
    // this is very easy in strings but in c string we have to apply loops for each characters which is hectic. 
    cout << str8.length() << endl; // can also check its length like this

    // for input of string:
    // string str9; 
    // cout << "Enter your string: " << endl; 
    // cin >> str9; // it will take input till we press enter 
    // cout << "OUtput of string: " << str9 << endl;
    
    string str10;
    cout << "Enter your string: ";
    getline(cin, str10); // it will take input of multiple strings and also we can pass optional delimiter at the end like '$'.
    cout << "OUtput of string: " << str10 << endl;

    // can also use loop 
    // same loop methods with string to print like cstring.

    // reverse a string:
    reverse(str8.begin(),str8.end()); // it is returning iteration also need header #include <algorithm>
    cout << str8 << endl;

    return 0;
}