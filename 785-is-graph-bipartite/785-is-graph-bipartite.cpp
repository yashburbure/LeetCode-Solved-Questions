class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<char> q;
        short int n=graph.size();
        vector<char> col(n,'n');
        short int tp,i,j;
        for( j=0;j<n;j++){
            if(col[j]=='n'){
                col[j]='b';
                q.push(j);
                while(q.size()){
                    tp=q.front();
                    q.pop();
                    for(i=0;i<graph[tp].size();i++){
                        if(col[graph[tp][i]]!='n') continue;
                        if(col[tp]=='b'){
                            col[graph[tp][i]]='r';
                            q.push(graph[tp][i]);
                        }
                        else{
                            col[graph[tp][i]]='b';
                            q.push(graph[tp][i]);
                        }
                    }
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<graph[i].size();j++){
                if(col[i]==col[graph[i][j]]) return false;
            }
        }
        return true;
    }
};