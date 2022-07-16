class Solution {
public:
    int dp[51][51][51];
    vector<pair<int,int>> movements={{1,0},{0,1},{-1,0},{0,-1}};
    const int M=1e9+7;
    bool is_safe(int &i,int &j,int &m,int &n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    long dfs(int &i,int &j,int &m,int &n,int &moverem){
        if(!is_safe(i,j,m,n)){
            return 1l;
        }
        if(moverem==0){
            return 0l;
        }
        if(dp[i][j][moverem]!=-1){
            return dp[i][j][moverem];
        }
        long ans=0l;
        for(auto &mov:movements){
            int v_x=mov.first+i;
            int v_y=mov.second+j;
            moverem--;
            ans=(ans+dfs(v_x,v_y,m,n,moverem))%M;
            moverem++;
        }
        return dp[i][j][moverem]=ans;
    }
    int findPaths(int &m, int &n, int &maxMove, int &startRow, int &startColumn) {
        memset(dp,-1,sizeof(dp));
        return dfs(startRow,startColumn,m,n,maxMove);
    }
};