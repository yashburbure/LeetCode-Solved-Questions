const int k=1001;
class Solution {
public:
    vector<int> g[k];
    bool detect_cycle(int vertex,int parent,vector<bool>& vis,vector<int>& path){
        vis[vertex]=true;
        for(auto &it:g[vertex]){
            if(it==parent) continue;
            if(vis[it]){
                path.push_back(it);
                return true;
            }
            path.push_back(it);
            if(detect_cycle(it,vertex,vis,path)) return true;
            path.pop_back();
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<pair<int,int>,int> mp;
        int i=0;
        for(auto &it:edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
            mp[{it[0],it[1]}]=i;
            i++;
        }
        vector<int> path={1};
        vector<bool> vis(edges.size(),false);
        bool is_cycle=detect_cycle(1,-1,vis,path);
        vis.resize(edges.size(),false);
        int index=-1;
        for(int i=0;i<path.size();i++){
            if(path[i]==path[path.size()-1]){
                index=i;
                break;
            }
        }
        pair<int,int> ans,curr;
        int mx_i=-1;
        for(int i=index;i<path.size()-1;i++){
            curr={path[i],path[i+1]};
            if(curr.first>curr.second){
                swap(curr.first,curr.second);
            }
            if(mp[curr]>mx_i){
                ans=curr;
                mx_i=mp[curr];
            }
        }
        return {ans.first,ans.second};
    }
};