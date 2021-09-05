// Problem : https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1#

// Reference : https://www.youtube.com/watch?v=Ylz6mwghDrU

/*
APPROACH 1 -> TC=O(n)  and SC=O(n)
*/
// Code :
int minimumNumberOfSwaps(string S){
        // code here 
        if(S.length()==0)
        return 0;
        vector<int>v;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='[')
            v.push_back(i);
        }
        
        int idx=0;
        int ans=0;
        int count=0;
        
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='[')
            {
                count++;
                idx++;
            }
            else
            {
                count--;
                if(count<0)
                {
                    ans=ans+(v[idx]-i);
                    swap(S[i],S[v[idx]]);
                    count=1;
                    idx++;
                }
            }
        }
        return ans;
    }


/*
APPROACH 2 -> TC=O(n)  and SC=O(1)
*/
// Code:
int minimumNumberOfSwaps(string S){
        // code here 
        int open=0;
        int close=0;
        int fault=0;
        int ans=0;

        for(int i=0;i<S.length();i++)
        {
            if(S[i]==']')
            {
                close++;
                fault=close-open;
            }
            else
            {
                open++;
                if(fault>0)
                {
                    ans=ans+fault;
                    fault--;
                }
            }
        }
        return ans;
    }