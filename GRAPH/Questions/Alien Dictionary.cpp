// Problem : https://practice.geeksforgeeks.org/problems/alien-dictionary/1#

// Reference : https://www.youtube.com/watch?v=wMMwRK-w0r4

//Code :
void dfs(int src,vector<vector<int>>&g,vector<int>&vis,string &ans)
    {
        vis[src]=1;
        
        for(auto it : g[src])
        {
            if(vis[it]==0)
            dfs(it,g,vis,ans);
        }
        char ch=src+'a';
        ans=ch+ans;
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>>g(K);
        for(int i=0;i<N-1;i++)
        {
            string w1=dict[i];
            string w2=dict[i+1];
            
            int len=min(w1.length(),w2.length());
            
            for(int j=0;j<len;j++)
            {
                if(w1[j]!=w2[j])
                {
                    g[w1[j]-'a'].push_back(w2[j]-'a');
                    break;
                }
            }
        }
        vector<int>vis(K,0);
        string ans="";
        for(int i=0;i<K;i++)
        {
            if(vis[i]==0)
            dfs(i,g,vis,ans);
        }
        return ans;
    }