// Problem : https://practice.geeksforgeeks.org/contest/coding-try-outs-amazon/problems#

// Reference :

// Code :
int rearrangeString(string str)
    {
        //code here
        //eg:aaabac here,max frequency=4(of character a)
        //then, abc will occur once, now we check whether we can arrange the leftover a's in 
        //between them or not.
        //_a_b_c_,here the dash before and after a is invalid because aa_b_c/_aab_c_ will have same adjacent
        //characters hence,it is invalid. So we have,total three 2 valid spaces but 3 leftover a's.
        //Hence not possible.
        //if(max_feq<=(len-max_freq+1) -> true -> then possible else not!
        
        int len=str.length();
        unordered_map<char,int>mp;
        int maxi=INT_MIN;
        for(int i=0;i<len;i++)
        {
            mp[str[i]]++;
            
            if(mp[str[i]]>maxi)
            maxi=mp[str[i]];
        }
        string temp="";
        
        if(maxi<=(len-maxi+1))
        return 1;
        
        else
        return 0;
        
    }

int main() {
	//code
	int t;
	cin>>t;
	string s;
	while(t--)
	{
	    cin>>s;
	    cout<< rearrangeString(s)<<"\n";
	}
	return 0;
}
