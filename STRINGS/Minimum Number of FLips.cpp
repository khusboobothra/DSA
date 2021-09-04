// Problem :https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1

//Reference : https://www.youtube.com/watch?v=F0E7k6X_kt8

//Code :
int minFlips (string S)
{
    // your code here
    int len=S.length();
    int c1=0;
    int c2=0;
    int ans=0;
    
    for(int i=0;i<len;i++)
    {
        //i&1:checks whether ith position is even or odd.
        //If i&1==0,i = even position and id i&1==1, then i = odd position.
        if(i%2==1 && S[i]=='0')
        c1++;
        if(i%2==1 && S[i]=='1')
        c2++;
        if(i%2==0 && S[i]=='1')
        c1++;
        if(i%2==0 && S[i]=='0')
        c2++;
    }
    ans=min(c1,c2);
    return ans;
}