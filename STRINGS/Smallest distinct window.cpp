// Problem : https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1

// Reference : https://www.youtube.com/watch?v=Q3iTTwgDb6U

// Code :
string findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int>mp;
        set<char>st;
        for(char c:str)
        {
            st.insert(c);
        }
        
        int n=st.size();
        int i=0;
        int j=1;
        int count=0;
        int ans=INT_MAX;
        mp[str[i]]++;
        count++;
        
        while(i<=j && j<str.length())
        {
            if(count<n)
            {
                if(mp[str[j]]==0)
                    count++;
                    
                    mp[str[j]]++;
                    j++;
            }
            else if(count==n)
            {
                ans=min(ans,j-i);
                if(mp[str[i]]==1)
                {
                    count--;
                }
                mp[str[i]]--;
                i++;
            }
        }
        
        
        while(count==n)
        {
            ans=min(ans,j-i);
            if(mp[str[i]]==1)
            count--;
            
            mp[str[i]]--;
            i++;
        }
         string val="";
         for(int k=0;k<ans;k++)
             val+="a";
    
    return val;
    }
