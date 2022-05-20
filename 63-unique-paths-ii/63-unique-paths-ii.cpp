int dp[102][102];
class Solution {
public:
    int find_ans(vector<vector<int>> obstacleGrid,int i,int j,int n,int m){
        if(obstacleGrid[i][j]==1) return 0; 
        if(dp[i][j]!=-1) return dp[i][j];
        int ans;
        if(i==n && j==m) return 1;
        else if(i==n){
            ans=find_ans(obstacleGrid,i,j+1,n,m);
        }
        else if(j==m){
            ans=find_ans(obstacleGrid,i+1,j,n,m);
        }
        else{
            ans=find_ans(obstacleGrid,i,j+1,n,m)+find_ans(obstacleGrid,i+1,j,n,m);
        }
        return dp[i][j]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=find_ans(obstacleGrid,0,0,n-1,m-1);
        return ans;
    }
};