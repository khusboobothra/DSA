//Problem : https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

//Solution :
void printDuplicates(string s)
{
    unordered_map<char,int>mp;
    for(auto c:s)
    {
        mp[s]++;
    }
    for(auto it:mp)
    {
        if(it.second>1)
        {
            cout<<it.first<<"->"<<it.second<<"\n";
        }
    }
}