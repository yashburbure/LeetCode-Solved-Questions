class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int dp[m+1][n+1];
        int ans=0;
        int ele;
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0) dp[i][j]=0;
                else if(matrix[i-1][j-1]=='1'){
                    ele=sqrt(min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}));
                    dp[i][j]=(1+ele)*(1+ele);
                }
                else{
                    dp[i][j]=0;
                }
                ans=max(ans,dp[i][j]);
            }
            cout<<endl;
        }
        return ans;
    }
};