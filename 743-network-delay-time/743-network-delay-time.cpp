class Solution {
public:
    vector<pair<int,int>> g[101];
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> timereq(n+1,INT_MAX);
        for(auto &it:times){
            g[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        pair<int,int> tp;
        q.push({0,k});
        timereq[k]=0;
        while(q.size()){
            tp=q.top();
            q.pop();
            for(auto &it:g[tp.second]){
                if(timereq[it.first]>timereq[tp.second]+it.second){
                    q.push({timereq[tp.second]+it.second,it.first});
                    timereq[it.first]=timereq[tp.second]+it.second;
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            ans=max(ans,timereq[i]);
        }
        return (ans==INT_MAX)?-1:ans;
    }
};