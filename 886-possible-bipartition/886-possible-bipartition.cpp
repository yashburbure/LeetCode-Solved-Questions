class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> g[n+1];
        for(auto &it:dislikes){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<char> color(n+1,'N');
        queue<int> q;
        int tp;
        for(int i=1;i<=n;i++){
            if(color[i]=='N'){
                q.push(i);
                color[i]='B';
                while(q.size()){
                    tp=q.front();
                    q.pop();
                    for(auto &it:g[tp]){
                        if(color[it]=='N'){
                            if(color[tp]=='B') color[it]='R';
                            else color[it]='B';
                            q.push(it);
                        }
                        else if(color[it]==color[tp]) return false;
                    }
                }
            }
        }
        return true;
    }
};