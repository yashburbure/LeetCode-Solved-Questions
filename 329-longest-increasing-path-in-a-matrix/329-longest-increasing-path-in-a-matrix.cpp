class Solution {
public:
    int n,m;
    vector<pair<int,int>> mov={{1,0},{-1,0},{0,1},{0,-1}};
    bool is_safe(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int lim(int i,int j,
            vector<vector<int>>& dp,vector<vector<int>>& matrix){
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=1;
        for(auto &m:mov){
            int v_x=i+m.first;
            int v_y=j+m.second;
            if(is_safe(v_x,v_y) && matrix[v_x][v_y]>matrix[i][j]){
                dp[i][j]=max(dp[i][j],1+lim(v_x,v_y,dp,matrix));
            }
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]!=-1){
                    continue;
                }
                dp[i][j]=lim(i,j,dp,matrix);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};