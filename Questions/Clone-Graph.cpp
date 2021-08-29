/*
Problrm :Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

https://www.interviewbit.com/problems/clone-graph/

Solution : Approach-> https://www.youtube.com/watch?v=f2EfGComRKM

*/

//Code :
class Solution {
    void dfs(Node* curr,Node* node,vector<Node *>& visited)
    {
        //Node* copy = new Node(node->val);
        visited[node->val] = node;
        for(auto ele: curr->neighbors)
        {
            if(visited[ele->val] == NULL)
            {
                Node *newnode = new Node(ele->val);
                (node->neighbors).push_back(newnode);
                dfs(ele,newnode,visited);
            }
            else
                (node->neighbors).push_back(visited[ele->val]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        
        vector<Node *> visited(1000,NULL);
        Node* copy = new Node(node->val);
        visited[node->val] = copy;
        //Iterate for all neighbors
        for(auto curr: node->neighbors)
        {
            if(visited[curr->val] == NULL)
            {
                Node *newnode = new Node(curr->val);
                (copy->neighbors).push_back(newnode);
                dfs(curr,newnode,visited);
            }
            else
                (copy->neighbors).push_back(visited[curr->val]);
        }
        return copy;
    }
};




//Shorter and Easy to Understand
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
map<UndirectedGraphNode * , UndirectedGraphNode *>mp;
//map<node of original graph, node of clone graph>
queue<UndirectedGraphNode *>q;
q.push(node);

mp[node]=new UndirectedGraphNode(node->label);

while(!q.empty())
{
    UndirectedGraphNode *temp=q.front();
    q.pop();
    vector<UndirectedGraphNode *>v(temp->neighbors);

    for(int i=0;i<v.size();i++)
    {
        if(mp.find(v[i])==mp.end())
        {
            mp[v[i]]=new UndirectedGraphNode(v[i]->label);
            q.push(v[i]);
        }
        mp[temp]->neighbors.push_back(mp[v[i]]);
    }
}
return mp[node];
}
