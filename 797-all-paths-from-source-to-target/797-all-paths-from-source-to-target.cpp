class Solution {
public:
    vector<vector<int>> AllPaths;
    int n;
    void dfs(int &vertex,int& parent,int vis,vector<int>& path,vector<vector<int>>& g){
        if(vertex==n-1){
            AllPaths.push_back(path);
            return;
        }
        vis|=(1<<vertex);
        for(auto &it:g[vertex]){
            if(it==parent) continue;
            if(vis&(1<<it)) continue;
            path.push_back(it);
            dfs(it,vertex,vis,path,g);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        vector<int> path={0};
        int parent=-1;
        int vertex=0;
        dfs(vertex,parent,0,path,graph);
        return AllPaths;
    }
};