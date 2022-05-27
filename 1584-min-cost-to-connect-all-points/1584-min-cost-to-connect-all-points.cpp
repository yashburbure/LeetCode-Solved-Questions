class Solution {
public:
    map<pair<int,int>,pair<int,int>> parent;
    map<pair<int,int>,int> sz;
    void make(pair<int,int> v){
        parent[v]=v;
        sz[v]=1;
    }
    pair<int,int> find(pair<int,int> v){
        if(parent[v]==v) return v;
        return parent[v]=find(parent[v]);
    }
    void Union(pair<int,int> u,pair<int,int> v){
        auto a=find(u);
        auto b=find(v);
        if(a!=b){
            if(sz[a]<sz[b]){
                parent[a]=b;
                sz[b]+=sz[a];
            }
            else{
                parent[b]=a;
                sz[a]+=sz[b];
            }
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int wt;
        vector<pair<int,pair<int,int>>> edges;
        for(auto &it:points){
            make({it[0],it[1]});
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({wt,{i,j}});
            }
        }
        int ans=0;
        sort(edges.begin(),edges.end(),[&](auto a,auto b){
            return a.first<b.first;
        });
        for(auto &it:edges){
            int wt=it.first;
            pair<int,int> pt1={points[it.second.first][0],points[it.second.first][1]};
            pair<int,int> pt2={points[it.second.second][0],points[it.second.second][1]};
            if(find(pt1)!=find(pt2)){
                ans+=wt;
                Union(pt1,pt2);
            }
        }
        return ans;
    }
};