class Solution {
public:
    vector<int> findOrder(int nc, vector<vector<int>>& pre) {
        vector<int> graph[nc];
        vector<int> indegree(nc,0);
        vector<int> Order;
        for(auto &it:pre){
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        short int i,tp;
        for(i=0;i<nc;i++){
            if(!indegree[i]){
                Order.push_back(i);
                q.push(i);
            }
        }
        while(q.size()){
            tp=q.front();
            q.pop();
            for(auto &it:graph[tp]){
                indegree[it]--;
                if(!indegree[it]){
                    q.push(it);
                    Order.push_back(it);
                }
            }
        }
        if(Order.size()!=nc) Order.clear();
        return Order;
    }
};