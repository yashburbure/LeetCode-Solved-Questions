class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()!=s1.length()+s2.length()) return 0;
        int n=s1.length();
        int m=s2.length();
        bool dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0&&j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]=(dp[i][j-1]&&s3[i+j-1]==s2[j-1]);
                else if(j==0) dp[i][j]=(dp[i-1][j]&&s3[i+j-1]==s1[i-1]);
                else{
                    dp[i][j]=(dp[i][j-1]&&s3[i+j-1]==s2[j-1]);
                    dp[i][j]|=(dp[i-1][j]&&s3[i+j-1]==s1[i-1]);
                }
            }
        }
        return dp[n][m];
    }
};