// Problem :

//Reference : https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/

//Code :
int countRev (string s)
{
    // your code here
    int len=s.length();
    if(len%2==1)
    return -1;
    
    stack<char>st;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='}' && !st.empty())
        {
            if(st.top()=='{')
            st.pop();
            else
            st.push(s[i]);
        }
        else
        {
            st.push(s[i]);
        }
    }
    double l=st.size();
    double open=0;
    while(!st.empty() && st.top()=='{')
    {
              open++;
              st.pop();
    }
    double close=l-open;
    //double o=open/2;
    //double c=close/2;
    
    return (ceil(open/2)+ceil(close/2));
}