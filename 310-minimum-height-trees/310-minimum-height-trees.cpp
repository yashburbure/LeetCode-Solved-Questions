
class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<int> indegree(n,0);
        vector<int> g[n];
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans;
        queue<int> q;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
                vis[i]=true;
            }
        }
        while(q.size()){
            int sz=q.size();
            ans.clear();
            for(int i=0;i<sz;i++){
                int tp=q.front();
                ans.push_back(tp);
                q.pop();
                for(auto &it:g[tp]){
                    if(vis[it]) continue;
                    indegree[it]--;
                    if(indegree[it]==1){
                        q.push(it);
                        vis[it]=true;
                    }
                }
            }
        }
        return ans;
    }
};