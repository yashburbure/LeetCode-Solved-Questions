class Solution {
public:
    int n,m;
    vector<pair<int,int>> movements={{1,0},{-1,0},{0,1},{0,-1}};
    bool is_safe(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void dfs(int i,int j,vector<vector<char>>& bo){
        bo[i][j]='-';
        for(auto &mov:movements){
            int v_x=i+mov.first;
            int v_y=j+mov.second;
            if(is_safe(v_x,v_y) && bo[v_x][v_y]=='O'){
                dfs(v_x,v_y,bo);
            }
        }
    }
    void solve(vector<vector<char>>& bo) {
        n=bo.size();
        m=bo[0].size();
        for(int i=0;i<m;i++){
            if(bo[0][i]=='O') dfs(0,i,bo);
            if(bo[n-1][i]=='O') dfs(n-1,i,bo);
        }
        for(int i=0;i<n;i++){
            if(bo[i][0]=='O') dfs(i,0,bo);
            if(bo[i][m-1]=='O') dfs(i,m-1,bo);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(bo[i][j]=='O' || bo[i][j]=='X') bo[i][j]='X';
                else bo[i][j]='O';
            }
        }
    }
};