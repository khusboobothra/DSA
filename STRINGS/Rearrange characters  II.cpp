// Problem : https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1

// Reference : https://www.youtube.com/watch?v=6YxNR56Gr4s

// Code :
string rearrangeString(string str)
    {
        //code here
        unordered_map<char,int>mp;
        int n=str.length();
        
        for(int i=0;i<n;i++)
        {
            mp[str[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(int i='a';i<='z';i++)
        {
            if(mp[i]>0)
            {
                pq.push({mp[i],i});
            }
            if(mp[i]>(n+1)/2)
            return "-1";
        }
        
        string res="";
        while(pq.size()>=2)
        {
            //first most occuring element
            pair<int,char>a=pq.top();
            pq.pop();
            //second most occuring element
            pair<int,char>b=pq.top();
            pq.pop();
            
            res=res+a.second;
            res=res+b.second;
            
            //cout<<a.second<<" "<<b.second<<"\n";
            if(a.first-1>0)
            pq.push({a.first-1,a.second});
            
            if(b.first-1>0)
            pq.push({b.first-1,b.second});
        }
        while(!pq.empty())
        {
            res=res+pq.top().second;
            pq.pop();
        }
    return res;    
    }