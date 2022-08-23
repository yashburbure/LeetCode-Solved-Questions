class Solution {
public:
    vector<vector<int>> ans;
    void cobsum(int ind,vector<int>& can,vector<int>& currComb,int tar){
        if(tar==0){
            ans.push_back(currComb);
            return;
        }
        if(ind==can.size()) return;
        for(int i=0;i*can[ind]<=tar;i++){
            if(i) currComb.push_back(can[ind]);
            cobsum(ind+1,can,currComb,tar-i*can[ind]);
        }
        while(currComb.size() && currComb[currComb.size()-1]==can[ind]) currComb.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        vector<int> currComb;
        cobsum(0,can,currComb,tar);
        return ans;
    }
};