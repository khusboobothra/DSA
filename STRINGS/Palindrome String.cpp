//Problem : https://practice.geeksforgeeks.org/problems/palindrome-string0817/1#

//Solution : 
int isPlaindrome(char S[])
{
    // Your code goes here
    int end=strlen(S)-1;
    int start=0;
    
    while(start<end)
    {
        if(S[start]!=S[end])
        return 0;
        
        start++;
        end--;
    }
    if(start>=end)
    return 1;
}
