//Problem: https://www.interviewbit.com/problems/delete-edge/

/*
//Approach: 
An efficient method can solve this problem in linear time by calculating the sum of both subtrees using total sum of the tree. We can get the sum of other tree by subtracting sum of one subtree from the total sum of tree, in this way subtree sum product can be calculated at each node in O(1) time.
First we calculate the weight of complete tree and then while doing the DFS at each node, we calculate its subtree sum, by using these two values we can calculate subtree sum product and maintain the maximum among all.
*/

//Solution:
#define ll long long int

map<int,vector<int>>mp;
ll res;
vector<bool>visit;
const ll mod = 1e9 + 7;

ll dfs(int src,vector<int>&A,ll s){
    
        visit[src] = true;    
        ll sum = 0;
        for(int neigh:mp[src]){
            if(visit[neigh])continue;
            
            int x = dfs(neigh,A,s);
            res = max(res%mod,(ll)((x%mod)*((s-x)%mod))%mod ) ;
            sum = (sum%mod + x%mod)%mod;
        }
        
        
    return  (sum%mod + A[src-1]%mod )%mod;
}


int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    
    visit.clear();
    mp.clear();
    for(vector<int>x:B){
        mp[x[0]].push_back(x[1]);
        mp[x[1]].push_back(x[0]);
    }
    
    res = 0;
    ll s = 0;
    for(int e:A)s = (s%mod + e%mod)%mod;
    
    visit.resize(A.size()+1,false);
    dfs(1,A,s);
    
    return res%mod;
}
