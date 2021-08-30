//Problem : https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/
//Code :

int split(string s)
{
    int n=s.length();
    int count0=0;
    int count1=0;
    int ans=-1;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            count0++;
        }
        else
        {
            count1++;
        }

        if(count0==count1)
        {
            ans++;
        }
    }
    return ans;
}