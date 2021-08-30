//Problem : https://leetcode.com/problems/count-and-say/

// Code :
string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        string s="11";
        for(int i=3;i<=n;i++)
        {
            string t="";
             s=s+'$';
            int counter=1;
            for(int j=1;j<s.size();j++)
            {
                if(s[j]!=s[j-1])
                {
                    t=t+to_string(counter);
                    t=t+s[j-1];
                    counter=1;
                }    
                else
                {
                    counter++;
                }
             
            }
            s=t;
        }
        return s;
    }
