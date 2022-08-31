vector<pair<int,int>> moves={{1,0},{-1,0},{0,1},{0,-1}};
int rowSize,colSize;
vector<vector<bool>> vis(201,vector<bool>(201,false));
int dp[201][201][2];
bool isInPacific(int &i,int &j){
    return (i<0 || j<0);
}
bool isInAtlantic(int &i,int &j){
    return (i>=rowSize || j>=colSize);
}
bool isSafe(int &i,int &j){
    return (i>=0 && j>=0 && i<rowSize && j<colSize);
}
bool canReach(int i,int j,vector<vector<int>>& heights,bool& flag){
    if(dp[i][j][flag]!=-1) return dp[i][j][flag];
    vis[i][j]=true;
    bool can=false;
    int vx,vy;
    for(auto &it:moves){
        vx=it.first+i;
        vy=it.second+j;
        if(isSafe(vx,vy)){
            if(!vis[vx][vy] && heights[vx][vy]<=heights[i][j]){
                can|=canReach(vx,vy,heights,flag);
            }
        }
        else{
            if(isInPacific(vx,vy) && !flag){
                can|=true;
            }
            else if(isInAtlantic(vx,vy) && flag){
                can|=true; 
            }
        }
    }
    vis[i][j]=false;
    if(can) dp[i][j][flag]=true;
    return can;
}
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rowSize=heights.size();
        colSize=heights[0].size();
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                vis[i][j]=false;
            }
        }
        memset(dp,-1,sizeof(dp));
        bool flag,can;
        vector<vector<int>> ans;
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                flag=false;
                dp[i][j][flag]=can=canReach(i,j,heights,flag);
                flag=true;
                dp[i][j][flag]=canReach(i,j,heights,flag);
                can&=dp[i][j][flag];
                if(can){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};