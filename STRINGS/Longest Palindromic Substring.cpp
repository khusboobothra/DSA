//Problem : https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1#

//Reference : https://www.youtube.com/watch?v=ZJUGtWObroc

//Code :

int lengthofPalin(int &low,int &end,string &S)
  {
      while(low>=0 && end<S.length())
      {
          if(S[low]==S[end])
          {
              low--;
              end++;
          }
          else
          break;
      }
      return end-low-1;
  }
    string longestPalin (string S) {
        // code here
    int low,end;
    
    int n=S.length();
    if(S.length()<=1)
    return S;
    int start=0;
    int maxLen=1;
    //for odd-length palindrome
    for(int i=0;i<n-1;i++)
    {
        int low=i;
        int end=i;
        int len=lengthofPalin(low,end,S);
        if(len>maxLen)
        {
            start=low+1;
            maxLen=len;
        }
    }
    
    
    //for even-length palindrome
    for(int i=0;i<n-1;i++)
    {
        int low=i;
        int end=i+1;
        int len=lengthofPalin(low,end,S);
        if(len>maxLen)
        {
            start=low+1;
            maxLen=len;
        }
    }
    return S.substr(start,maxLen);
    }
