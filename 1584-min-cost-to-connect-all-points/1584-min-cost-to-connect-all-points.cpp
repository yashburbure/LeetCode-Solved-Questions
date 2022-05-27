#define pii pair<int,int> 
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
        vector<pair<int,pair<pii,pii>>> edges;
        for(auto &it:points){
            make({it[0],it[1]});
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                pair<int,pair<pii,pii>> obj;
                obj.first=diff;
                obj.second.first={points[i][0],points[i][1]};
                obj.second.second={points[j][0],points[j][1]};
                edges.push_back(obj);
            }
        }
        int ans=0;
        sort(edges.begin(),edges.end(),[&](auto a,auto b){
            return a.first<b.first;
        });
        for(auto &it:edges){
            int wt=it.first;
            auto pt1=it.second.first;
            auto pt2=it.second.second;
            if(find(pt1)!=find(pt2)){
                ans+=wt;
                Union(pt1,pt2);
            }
        }
        return ans;
    }
};