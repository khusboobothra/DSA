// problem : https://leetcode.com/problems/reconstruct-itinerary/

//Solution :

map<string,priority_queue<string,vector<string>,greater<string>>>adj;
vector<string>ans;

void dfs(string s)
{
    while(adj[s].size())
    {
        auto it=adj[s].top();
        adj[s].pop();
        dfs(it);
    }
    ans.push_back(s);
}


vector<string> findItinerary(vector<vector<string>>& tickets) {

for(int i=0;i<tickets.size();i++)
{
    adj[tickets[i][0]].push(tickets[i][1]);    
}

dfs("JFK");
reverse(ans.begin(),ans.end());
return ans;
}
