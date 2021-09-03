// https://leetcode.com/problems/first-bad-version/

/*
Implementation of binary search in arrays

LOGIC : The problem can be solved by iterating over all the products from 1 to n and calling the API to check if the respective product is good or bad. But as we are asked to minimize the number of API calls, which in software development is a critical factor of an application's efficiency, we need to think of a better approach.

If the explanation above provoked the idea of binary search in your mind, then yes, you are absolutely right my friend. It is a straightforward implementation of binary search, except that instead of being given an array to use its values, we are given a function to call as per our need. So just as usual, we calculate the mid-value and then call the API isBadVersion(mid), if it returns falls, it means we are in the zone of bad products and need to shift or search space to (mid-1), as mid is already a faulty product. We also assign this mid to our "res" variable which keeps track of the starting index of the bad product. If the API call returns true, it means we are in the range of good product and now we need to shift our left index of search space to mid+1.
*/

//Code :
int firstBadVersion(int n) {
        int l=1;
        int r=n;
        int pos=1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(isBadVersion(mid)==true)
            {
                pos=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return pos;
}