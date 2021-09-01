//Problem : https://leetcode.com/problems/word-break/

//Reference : https://www.youtube.com/watch?v=th4OnoGasMU

//Code :
int dp[1101];

int solve(int i,string s,set<string>&st)
{
    if(i==s.size())
    return 1;

    if(dp[i]!=-1)
    return dp[i];

    string temp;
    for(int j=i;j<s.size();j++)
    {
        temp=temp+s[j];
        if(st.find(temp)!=st.end())
        //temp is present in the set, now check from j+1 to end
        {
            if(solve(j+1,s,st))
            return dp[i]=1;
        }
    }
    return dp[i]=0;
}

bool wordBreak(string s, vector<string>& wordDict) {
      set<string>st;
      for(auto a:wordDict)
      {
          st.insert(a);
      }  
      return solve(0,s,st);
}

