vector<vector<int>> ans;
unordered_map<int,bool> mp;
vector<int> curr;
void combineRec(int ind,int &n,int &k,int bitmask){
    if(mp[bitmask]){
        return;
    }
    mp[bitmask]=true;
    if(ind==k){
        ans.push_back(curr);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!(bitmask&(1<<i))){
            curr.push_back(i);
            combineRec(ind+1,n,k,bitmask|(1<<i));
            curr.pop_back();
        }
    }
}
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        curr.clear();
        mp.clear();
        combineRec(0,n,k,0);
        return ans;
    }
};