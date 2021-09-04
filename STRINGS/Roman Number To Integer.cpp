// Problem : https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1

// Reference : https://www.youtube.com/watch?v=dlATMslQ6Uc

// Code :
int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        int n=str.length();
        
        int result=mp[str[n-1]];
        for(int i=n-2;i>=0;i--)
        {
            if(mp[str[i]]<mp[str[i+1]])
            {
                //subtraction
                result=result-mp[str[i]];
            }
            else
            {
                //addition
                result=result+mp[str[i]];
            }
            
        }
        return result;
    }