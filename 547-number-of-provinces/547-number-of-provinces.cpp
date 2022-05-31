class Solution {
public:
    void dfs(int i,int &n,vector<vector<int>>& isConnected,vector<int>& vis){
        vis[i]=1;
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==0 || vis[j]) continue;
            dfs(j,n,isConnected,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            ans++;
            dfs(i,n,isConnected,vis);
        }
        return ans;
    }
};