/*
Problem : You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. Since this multiple could be large, return it in form of a string.

Note:
Returned string should not contain leading zeroes.

https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/
*/

/*
BFS: Starting from string “1”, we can concatenate 0’s or 1’s at the end of the string in search of such a string which is multiple of the given number.

Approach : https://afteracademy.com/blog/smallest-multiple-with-0-and-1

*/

//Code
int mod(string t, int N)
{
    int r = 0;
    for (int i = 0; i < t.length(); i++)
    {
        r = r * 10 + (t[i] - '0');
        r %= N;
    }
    return r;
}

string Solution::multiple(int A) {
    queue<string> q;
    set<int> visit;
 
    string t = "1";
 
    //  In starting push 1 into our queue
    q.push(t);
 
    //  loop until queue is not empty
    while (!q.empty())
    {
        // Take the front number from queue.
        t = q.front(); 
             q.pop();
 
        // Find remainder of t with respect to N.
        int rem = mod(t, A);
 
        // if remainder is 0 then we have
        // found our solution
        if (rem == 0)
            return t;
 
        // If this remainder is not previously seen,
        // then push t0 and t1 in our queue
        else if(visit.find(rem) == visit.end())
        {
            visit.insert(rem);
            q.push(t + "0");
            q.push(t + "1");
        }
    }
}


