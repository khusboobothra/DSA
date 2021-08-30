//Problem : https://www.geeksforgeeks.org/print-subsequences-string/

//Reference : https://www.youtube.com/watch?v=b7AYbpM5YrE

//Code : Using bit manipulation

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
#include <bits/stdc++.h>
using namespace std;
 
// Find all subsequences
void printSubsequence(string input, string output)
{
    // Base Case
    // if the input is empty print the output string
    if (input.empty()) {
        cout << output << endl;
        return;
    }
 
    // output is passed with including
    // the Ist character of
    // Input string
    //S.substr(starting position of the substring[1st parameter], length of the substring[2nd and optional parameter])
    printSubsequence(input.substr(1), output + input[0]);
 
    // output is passed without
    // including the Ist character
    // of Input string
    printSubsequence(input.substr(1), output);
}
 
// Driver code
int main()
{
    // output is set to null before passing in as a
    // parameter
    string output = "";
    string input = "abcd";
 
    printSubsequence(input, output);
 
    return 0;
}