class Solution {
public:
    vector<pair<int,int>> mov={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    bool is_safe(int i,int j,int n){
        return i>=0 && j>=0 && i<n && j<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        queue<pair<int,int>> q;
        int v_x,v_y;
        int n=grid.size();
        q.push({0,0});
        vector<vector<int>> level(n,vector<int>(n,INT_MAX));
        pair<int,int> curr;
        level[0][0]=1;
        while(q.size()){
            curr=q.front();
            q.pop();
            for(auto &m:mov){
                v_x=m.first+curr.first;
                v_y=m.second+curr.second;
                if(is_safe(v_x,v_y,n) && grid[v_x][v_y]==0 ){
                    if(level[v_x][v_y]>level[curr.first][curr.second]+1){
                        q.push({v_x,v_y});
                        level[v_x][v_y]=level[curr.first][curr.second]+1;
                    }
                }
            }
        }
        return (level[n-1][n-1]==INT_MAX)?-1:level[n-1][n-1];
    }
};