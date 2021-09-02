// Problem : https://practice.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1

//Code :
string printSequence(string S)
{
    //code here.
    string str[] = {"2","22","222",
                    "3","33","333",
                    "4","44","444",
                    "5","55","555",
                    "6","66","666",
                    "7","77","777","7777",
                    "8","88","888",
                    "9","99","999","9999"
                   };
                   
    string output="";
    int n=S.length();
    for(int i=0;i<n;i++)
    {
        if(S[i] == ' ')
        output=output+'0';
        else
        {
            int pos=S[i]-'A';
            output=output+str[pos];
        }
    }
    return output;
}