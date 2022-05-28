const int k=1e6+7;
class Solution {
public:
    int parent[k],sz[k];
    void make(int v){
        parent[v]=v;
        sz[v]=1;
    }
    int find(int &v){
        if(parent[v]==v) return v;
        return parent[v]=find(parent[v]);
    }
    void Union(int &u,int &v){
        int a=find(u);
        int b=find(v);
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
    int minCostConnectPoints(vector<vector<int>>& pt) {
        int n=pt.size();
        vector<pair<int,int>> points;
        for(auto &it:pt){
            points.push_back({it[0],it[1]});
        }
        int wt;
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<n;i++){
            make(i);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                wt=abs(points[i].first-points[j].first)
                    +abs(points[i].second-points[j].second);
                edges.push_back({wt,{i,j}});
            }
        }
        int ans=0;
        sort(edges.begin(),edges.end(),[&](auto& a,auto& b){
            return a.first<b.first;
        });
        for(auto &it:edges){
            int wt=it.first;
            int pt1=it.second.first;
            int pt2=it.second.second;
            if(find(pt1)!=find(pt2)){
                ans+=wt;
                Union(pt1,pt2);
            }
        }
        return ans;
    }
};