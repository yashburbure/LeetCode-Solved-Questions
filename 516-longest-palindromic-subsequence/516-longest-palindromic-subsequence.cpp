class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        int dp[n][n];
        int ans=1;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            for(int j=i-1;j>=0;j--){
                if(s[i]==s[j]){
                    if(i-j==1) dp[i][j]=2;
                    else dp[i][j]=max(2+dp[i-1][j+1],dp[i-1][j]);
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j+1]);
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
