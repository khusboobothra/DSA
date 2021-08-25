//Problem : https://www.interviewbit.com/problems/level-order/

//Code : 
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>>v;
    vector<int>value;
    if(A==NULL)
    return v;

    value.push_back(A->val);
    queue<TreeNode*>q;
    q.push(A);
    v.push_back(value);

    while(!q.empty())
    {
        vector<int>temp;
        int sz=q.size();
        while(sz--)
        {
            if(q.front()->left!=NULL)
            {
                q.push(q.front()->left);
                temp.push_back(q.front()->left->val);
            }
            if(q.front()->right!=NULL)
            {
                q.push(q.front()->right);
                temp.push_back(q.front()->right->val);
            }
             q.pop();
        }
         if(!temp.empty())
            v.push_back(temp); 
    }
     return v;
}