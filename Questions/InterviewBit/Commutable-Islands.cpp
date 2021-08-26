/*
There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.
We need to find bridges with minimal cost such that all islands are connected.
It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Input Format:
The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3:
    => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].
Output Format:

Return an integer representing the minimal cost required.



https://www.interviewbit.com/problems/commutable-islands/

*/

//Code
bool comp(vector<int>a,vector<int>b)
{
    return a[2]<b[2];
}

int find(vector<int>&parent,int i)
{
    if(parent[i]==-1)
    return i;

    return parent[i]=find(parent,parent[i]);
}

void Union(int u,int v,vector<int>&parent)
{
    int uu=find(parent,u);
    int vv=find(parent,v);

    parent[vv]=uu;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int>parent(A+1);
    for(int i=0;i<A;i++)
    parent[i]=-1;
    

    sort(B.begin(),B.end(),comp);
    int ans=0;

    for(int i=0;i<B.size();i++)
    {
        int u=find(parent,B[i][0]-1);
        int v=find(parent,B[i][1]-1);

        if(u!=v)
        {
            Union(u,v,parent);
            ans=ans+B[i][2];
        }
    }
    return ans;
}
