// Problem : https://leetcode.com/problems/reverse-string/

//Solution : 
 void reverseString(vector<char>& s) {
        int end=s.size()-1;
        int start=0;
        while(start<end)
        {
            char c=s[start];
            s[start]=s[end];
            s[end]=c;
            start++;
            end--;
        }
    }
