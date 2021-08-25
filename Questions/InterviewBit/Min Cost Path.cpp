/*Problem:You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.
Your target is to go from top left corner to the bottom right corner of the matrix.

But there are some restrictions while moving along the matrix:

If you follow what is written in the cell then you can move freely.
But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.

https://www.interviewbit.com/problems/min-cost-path/

*/

//Solution : https://www.youtube.com/watch?v=VSKkW1JsXr0

//Code Implementation : 
//Dijstra's Algorithm
struct Point{
    public:
    int x;
    int y;
    int cost;
};

struct comp{
    bool operator()(Point &p1,Point &p2)
    {
        return p1.cost>p2.cost;
    }
};

// R D L U
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int Solution::solve(int A, int B, vector<string> &C) {
    int row=A;
    int col=B;
//for all possible directions
string s="RDLU";

//to store distance
vector<vector<int>>dis(row,vector<int>(col,INT_MAX-1));
//to get the min-cost path

priority_queue<Point,vector<Point>,comp>pq;


//push the initial co-ordinates
pq.push({0,0,0});
dis[0][0]=0;

while(!pq.empty())
{
    //minimum cost co-ordinates
    Point currentPoint=pq.top();
    pq.pop();

    //destination reached
    if(x==row-1 && y==col-1 &&)
    return dis[currentPoint.x][currentPoint.y];

    for(int i=0;i<4;i++)
    {
        int xx=currentPoint.x+dx[i];
        int yy=currentPoint.y+dy[i];
        int cost=dis[currentPoint.x][currentPoint.y];

        if(s[i]!=C[currentPoint.x][currentPoint.y])
        cost++;

        //check boundary condition and cost
        if(xx<row && yy<col && xx>=0 && yy>=0 && (cost<dis[xx][yy]))
        {
            pq.push({xx,yy,cost});
            dis[xx][yy]=cost;
        }
    }
}
return dis[row-1][col-1];
}


//Using deque data structure




