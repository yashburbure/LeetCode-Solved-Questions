class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        vector<int> dp(row+1,0);
        vector<int> previous(row+1,0);
        int ans=INT_MAX;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=triangle[i-1].size();j++){
                if(j==1){
                    dp[j]=triangle[i-1][j-1]+previous[j];
                }
                else if(j==triangle[i-1].size()){
                    dp[j]=triangle[i-1][j-1]+previous[j-1];
                }
                else{
                    dp[j]=min(triangle[i-1][j-1]+previous[j-1],
                             triangle[i-1][j-1]+previous[j]);
                }
                if(i==row) ans=min(ans,dp[j]);
            }
            for(int j=0;j<=triangle[i-1].size();j++){
                previous[j]=dp[j];
            }
        }
        return ans;
    }
};