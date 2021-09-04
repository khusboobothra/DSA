// Problem : https://leetcode.com/problems/squares-of-a-sorted-array/

//Reference : https://leetcode.com/problems/squares-of-a-sorted-array/discuss/495394/C%2B%2B%3A-Simplest-one-pass-two-pointers

// Code :
vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int l=0,r=n-1;
        
        for(int i=n-1;i>=0;i--)
        {
             if(abs(nums[l])>abs(nums[r]))
             {
                 ans[i]=nums[l]*nums[l];
                 l++;
             }
            else
            {
                ans[i]=nums[r]*nums[r];
                r--;
            }
        }
        return ans;
    }