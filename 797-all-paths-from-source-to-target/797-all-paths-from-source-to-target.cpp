class Solution {
public:
    vector<vector<int>> AllPaths;
    int n;
    void dfs(int &vertex,int& parent,vector<bool> vis,vector<int>& path,vector<vector<int>>& g){
        if(vertex==n-1){
            AllPaths.push_back(path);
            return;
        }
        vis[vertex]=true;
        for(auto &it:g[vertex]){
            if(it==parent) continue;
            if(vis[it]) continue;
            path.push_back(it);
            dfs(it,vertex,vis,path,g);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        vector<bool> vis(n,false);
        vector<int> path={0};
        int parent=-1;
        int vertex=0;
        dfs(vertex,parent,vis,path,graph);
        return AllPaths;
    }
};