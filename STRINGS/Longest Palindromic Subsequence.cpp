// Problem: https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

// Reference : DP-Aditya Verma

// Code :
int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<n+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
               if(text1[i-1]==text2[j-1]){
                  dp[i][j]= 1+dp[i-1][j-1];
               }else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               } 
            }
        }
        return dp[m][n];
    }
    int longestPalinSubseq(string A) {
        //code here
        //In here, we cannot do string B=reverse(A.begin(),A.end()) because reverse is a void fucntion in cpp
        //and we cannot store it in string value.Hence,do string b=a;then apply reverse(b.begin(),b.end()
        string B=A;
        reverse(B.begin(),B.end());
        return longestCommonSubsequence(A,B);
        
    }