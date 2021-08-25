//Problem : https://www.interviewbit.com/problems/snake-ladder-problem/

//Code : 
int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
     unordered_map<int,int>snake,ladder;

    for(auto it:A)
    {
        ladder[it[0]]=it[1];
    }
    for(auto it:B)
    {
        snake[it[0]]=it[1];
    }

    bool visited[101]={false};
    //queue for level order traversal
    queue<int>q;
    q.push(1);
    visited[1]=true;
    

    int level=0;
    while(!q.empty())
    {
       int sz=q.size();
       //remove all the nodes of the current level
       while(sz--)
       {
           int pos=q.front();
           q.pop();

           //if we have reached the destination
           if(pos==100)
           return level;

           for(int i=1;i<=6;i++)
           {
               //check if the next position is within the boundary or not.Also visited or not
               if(pos+i<=100 && visited[pos+i]==false)
               {
                   int newPos=pos+i;

                   //if snake is present
                   if(snake.find(newPos)!=snake.end())
                   {
                       visited[newPos]=true;
                       newPos=snake[newPos];
                   }

                   //if ladder is present
                   if(ladder.find(newPos)!=ladder.end())
                   {
                       visited[newPos]=true;
                       newPos=ladder[newPos];
                   }

                   if(visited[newPos]==false)
                   {
                       q.push(newPos);
                       visited[newPos]=true;
                   }
               }
           }
       }
       level++;
    }
    return -1;    
}
