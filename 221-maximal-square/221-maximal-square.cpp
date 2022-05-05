class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int previous[n+1];
        for(int i=0;i<=n;i++) previous[i]=0;
        int dp[n+1];
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(j==0) dp[j]=0;
                else{
                    if(matrix[i-1][j-1]=='0') dp[j]=0;
                    else{
                        dp[j]=1;
                        int ele=sqrt(min({previous[j-1],previous[j],dp[j-1]}));
                        dp[j]=(ele+1)*(ele+1);
                    }
                }
                ans=max(ans,dp[j]);
            }
            for(int j=0;j<=n;j++) previous[j]=dp[j];
        }
        return ans;
    }
};