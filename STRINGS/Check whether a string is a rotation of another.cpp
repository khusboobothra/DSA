//Problem : https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1

/*
Approach : In order to solve this problem, we will firstly check if the Strings are of same length. After that we will concatenate the first string with itself, then check whether the second one is present in the concatenated string or not. This is because if you join a String with itself then it actually contains all rotated versions of itself. 
If the second String exists in the concatenated String, the Strings are rotations of each other. In our example, for S1="HELLO",  the concatenated String will be "HELLOHELLO". As we can see, this concatenated string contains the String "LOHEL" and thus, these Strings are rotations of each other.

*/

//Solution : 
bool areRotations(string s1,string s2)
{
    if(s1.length()!=s2.length())
    return false;

    return (temp.find(s2)!=string::npos);
}


/*
string::npos = It actually means the end of the string.This as a return value indicates match not found.
*/
