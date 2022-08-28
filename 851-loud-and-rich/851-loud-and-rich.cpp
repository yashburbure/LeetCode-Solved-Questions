const int N=505;
vector<int> g[N];
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        for(int i=0;i<N;i++) g[i].clear();
        int n=quiet.size();
        int indegree[505]={0};
        for(int i=0;i<richer.size();i++){
            g[richer[i][0]].push_back(richer[i][1]);
            indegree[richer[i][1]]++;
        }
        queue<int> q;
        vector<int> ans(n);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            ans[i]=i;
            if(!indegree[i]){
                q.push(i);
                vis[i]=true;
            }
        }
        int tp;
        while(q.size()){
            tp=q.front();
            q.pop();
            for(auto &it:g[tp]){
                if(quiet[ans[it]]>quiet[ans[tp]]){
                    ans[it]=ans[tp];
                    vis[it]=true;
                    q.push(it);
                }
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};