class Solution {
public:
    bool canFinish(int &nc, vector<vector<int>>& pre) {
        vector<set<short int>> graph1(nc);
        vector<short int> graph2[nc];
        for(auto &it:pre){
            graph1[it[0]].insert(it[1]);
            graph2[it[1]].push_back(it[0]);
        }
        queue<short int> q;
        vector<bool> vis(nc,0);
        for(short int i=0;i<nc;i++){
            if(graph1[i].size()==0){
                q.push(i);
                vis[i]=1;
            }
        }
        short int tp;
        while(q.size()){
            tp=q.front();
            q.pop();
            for(short int &it:graph2[tp]){
                graph1[it].erase(graph1[it].lower_bound(tp));
                if(!graph1[it].size()){
                    vis[it]=1;
                    q.push(it);
                } 
            }
        }
        for(short int i=0;i<nc;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};