class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int dp[m+1][n+1];
        int ans=0;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0) dp[i][j]=0;
                else{
                    if(matrix[i-1][j-1]=='1'){
                        dp[i][j]=1;
                        if(dp[i-1][j-1]){
                            int ele=sqrt(min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}));
                            dp[i][j]=(ele+1)*(ele+1);
                        }
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};