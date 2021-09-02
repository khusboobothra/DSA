// Problem : https://practice.geeksforgeeks.org/problems/search-pattern0205/1

//Reference :Gfg Article +  https://www.youtube.com/watch?v=GTJr8OvyEVQ

//Code :
vector<int>ans;
    void prefixArray(string &pat,int lps[])
    {
        int m=pat.length();
        int len=0;
        int i=1;
        lps[0]=0;
        while(i<m)
        {
            if(pat[i]==pat[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                {
                    len=lps[len-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    
    void KMP(string &pat,string &txt)
    {
        int n=txt.length();
        int m=pat.length();
        int lps[m];
        prefixArray(pat,lps);
        int i=0;//i for txt
        int j=0;//j for pat
        
        while(i<n)
        {
            if(txt[i]==pat[j])
            {
                i++;
                j++;
            }
            
            if(j==m)
            {
                ans.push_back(i-j+1);
                j=lps[j-1];
            }
            else if(i<n && txt[i]!=pat[j])
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else
                {
                    i=i+1;
                }
            }
        }
        
    }
    
        vector <int> search(string pat, string txt)
        {
            //code hee.
            KMP(pat,txt);
            return ans;
        }