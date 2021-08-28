/*
Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.
The above figure details the movements for a knight ( 8 possibilities ).
If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.

https://www.interviewbit.com/problems/knight-on-chess-board/

*/

//Solution
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    if(C==E && D==F)
    return 0;
    int row=A;
    int col=B;
    //position of knight/source = (C-1,D-1)
    //destination = (E-1,F-1)
    queue<pair<int,int>>q;
    q.push(make_pair(C-1,D-1));
    bool visited[A+1][B+1];
    memset(visited, false, sizeof(visited));
    visited[C-1][D-1] = true;

    int dx[8]={2,2,-2,-2,-1,1,-1,1};
    int dy[8]={1,-1,1,-1,2,2,-2,-2};
    int count=0;
    while(!q.empty())
    {
        int sz=q.size();
        count++;
        while(sz--){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int i=0;i<8;i++)
        {
            int rx=r+dx[i];
            int cy=c+dy[i];

            if(rx>=0 && cy>=0 && rx<row && cy<col && visited[rx][cy]==false)
            {
                visited[rx][cy] = true;
                if(rx==E-1 && cy==F-1)
                return count;
                q.push(make_pair(rx,cy));
            }
        }
        }

    }
return -1;
}
