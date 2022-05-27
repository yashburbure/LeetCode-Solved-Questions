class Solution {
public:
    vector<pair<int,int>> g[105];
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int k) {
        for(auto &it:fl){
            g[it[0]].push_back({it[1],it[2]});
        }
        vector<int> price(n+1,INT_MAX);
        queue<tuple<int,int,int>> q;
        q.push({src,-1,0});
        price[src]=0;
        while(q.size()){
            auto curr=q.front();
            q.pop();
            if(get<1>(curr)>=k) continue;
            for(auto &it:g[get<0>(curr)]){
                if(get<2>(curr)+it.second<price[it.first]){
                    q.push({it.first,get<1>(curr)+1,get<2>(curr)+it.second});
                    price[it.first]=min(price[it.first],get<2>(curr)+it.second);
                }
            }
        }
        return (price[dst]==INT_MAX)?-1:price[dst];
    }
};