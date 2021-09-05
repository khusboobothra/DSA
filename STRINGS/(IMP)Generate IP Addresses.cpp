// Problem : https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1

//Reference : https://www.youtube.com/watch?v=g1SOXwvSqe4

// Code :
bool isValid_subpart(string s,int i,int j)
  {
      int len=j-i+1;
      
      if(len>3)
      return false;
      
      if(s[i]=='0')
      {
          if(len==1)
          return true;
          
          return false;
      }
      
      int num=stoi(s.substr(i,j-i+1));
      if(num>=0 && num<256)
      {
          return true;
      }
      return false;
  }
  
  
  
  bool isValid_ip(int i,int j,int k,string s,int n)
  {
     if( isValid_subpart(s,0,i) && isValid_subpart(s,i+1,j) && 
         isValid_subpart(s,j+1,k) && isValid_subpart(s,k+1,n-1))
         return true;
         
         return false;
  }
  
  void add_string(int i,int j,int k,string s,int n,vector<string>&ans)
  {
      string temp;
      temp.append(s.substr(0,i+1));
      temp.push_back('.');
      temp.append(s.substr(i+1,j-i));
      temp.push_back('.');
      temp.append(s.substr(j+1,k-j));
      temp.push_back('.');
      temp.append(s.substr(k+1,n-k-1));
      
      ans.push_back(temp);
  }
  
  
    vector<string> genIp(string &s) {
        // Your code here
        int n=s.length();
        vector<string>ans;
        
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                for(int k=j+1;k<n-1;k++)
                {
                    if(isValid_ip(i,j,k,s,n))
                    add_string(i,j,k,s,n,ans);
                }
            }
        }
        return ans;
    }