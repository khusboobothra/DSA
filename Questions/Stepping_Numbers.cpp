void bfs(int A,int B,int i,vector<int>&res)
{
    queue<int>q;
    q.push(i);

    while(!q.empty())
    {
        int stepNum=q.front();
        q.pop();

        if(stepNum>=A && stepNum<=B)
        {
            res.push_back(stepNum);
        }
        //If Stepping Number is 0 or greater than m,
        // no need to explore the neighbors
        if(stepNum > B || i==0)
            continue;


        int lastDigit=stepNum%10;

        int stepNumA=stepNum*10+(lastDigit-1);
        int stepNumB=stepNum*10+(lastDigit+1);

        if(lastDigit==0)
        {
            q.push(stepNumB);
        }
        else if(lastDigit==9)
        {
            q.push(stepNumA);
        }
        else
        {
            q.push(stepNumA);
            q.push(stepNumB);
        }
    }
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int>res;
    for(int i=0;i<=9;i++)
    {
        bfs(A,B,i,res);
    }
    sort(res.begin(),res.end());
    return res;
}
