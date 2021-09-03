// Problem : https://leetcode.com/problems/longest-common-prefix/

//Code :
string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        sort(strs.begin(),strs.end());
    
            string w1=strs[0];
            string w2=strs[n-1];
            
            int len=min(w1.length(),w2.length());
            
            for(int j=0;j<len;j++)
            {
                if(w1[j]==w2[j])
                {
                    ans=ans+w1[j];
                }
                else
                {
                    break;
                }
            }
       return ans; 
    }