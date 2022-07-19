class Solution {
public:
    vector<int> findOrder(int nc, vector<vector<int>>& pre) {
        vector<short int> graph[nc];
        vector<short int> indegree(nc,0);
        vector<int> Order;
        short int i,tp;
        for(i=0;i<pre.size();i++){
            graph[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        queue<short int> q;
        for(i=0;i<nc;i++){
            if(!indegree[i]){
                Order.push_back(i);
                q.push(i);
            }
        }
        while(q.size()){
            tp=q.front();
            q.pop();
            for(short int &it:graph[tp]){
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