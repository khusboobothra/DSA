// Problem : https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1

//Code :
string secFrequent (string arr[], int n)
    {
        //code here.
        int fmax=INT_MIN,smax=INT_MIN;
        unordered_map<string,int>mp;
        mp.clear();
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;      
        }
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>fmax)
            {
                smax=fmax;
                fmax=it->second;
            }
            else if(it->second>smax && it->second<fmax)
            {
                smax=it->second;
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==smax)
            return it->first;
        }
    }