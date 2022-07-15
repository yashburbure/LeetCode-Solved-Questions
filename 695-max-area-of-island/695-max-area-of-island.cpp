class Solution {
public:
    vector<pair<short int,short int>> movements={{1,0},{-1,0},{0,1},{0,-1}};
    bool is_safe(short int& i,short int& j,short int& n,short int& m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    short int bfs(short int &i,short int &j,short int& row,short int& col,
             vector<vector<int>>& grid,vector<vector<bool>>& vis){
        short int v_x,v_y;
        queue<pair<short int,short int>> q;
        pair<short int,short int> curr;
        q.push({i,j});
        vis[i][j]=1;
        short int connected=0;
        while(!q.empty()){
            curr=q.front();
            q.pop();
            connected++;
            for(auto &mov:movements){
                v_x=mov.first+curr.first;
                v_y=mov.second+curr.second;
                if(is_safe(v_x,v_y,row,col) && grid[v_x][v_y]){
                    if(!vis[v_x][v_y]){
                        q.push({v_x,v_y});
                        vis[v_x][v_y]=1;
                    }
                }
            }
        }
        return connected;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        short int row=grid.size();
        short int col=grid[0].size();
        short int ans=0,i,j;
        vector<vector<bool>> vis(row,vector<bool>(col,0));
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(grid[i][j] && !vis[i][j]){
                    
                    ans=max(ans,bfs(i,j,row,col,grid,vis));
                }
                else{
                    vis[i][j]=1;
                }
            }
        }
        return ans;
    }
};