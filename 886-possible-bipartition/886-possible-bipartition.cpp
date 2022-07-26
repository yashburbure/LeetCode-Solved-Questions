const int k=2001;
class Solution {
public:
    vector<int> g[k];
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(auto &it:dislikes){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<char> color(n+1,'N');
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(color[i]=='N'){
                q;
                q.push(i);
                color[i]='B';
                int tp;
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