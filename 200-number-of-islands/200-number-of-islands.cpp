class Solution {
public:
    int n,m;
    vector<pair<int,int>> movements={{1,0},{-1,0},{0,-1},{0,1}};
    bool is_safe(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void dfs(int i,int j,vector<vector<int>> & vis,vector<vector<char>> &grid){
        vis[i][j]=1;
        for(auto &mov:movements){
            int v_x=mov.first+i;
            int v_y=mov.second+j;
            if(is_safe(v_x,v_y) && vis[v_x][v_y]==0 && grid[v_x][v_y]=='1'){
                dfs(v_x,v_y,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] || grid[i][j]=='0') continue;
                dfs(i,j,vis,grid);
                ans++;
            }
        }
        return ans;
    }
};