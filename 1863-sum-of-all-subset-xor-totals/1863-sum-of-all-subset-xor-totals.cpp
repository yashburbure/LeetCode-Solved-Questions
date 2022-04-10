class Solution {
public:
    void generate_subset(int i,int n,vector<int>& nums,vector<int> curr_set,vector<vector<int>>& subsets){
        if(i==n){
            if(curr_set.size()){
                subsets.push_back(curr_set);
            }
            return;
        }
        vector<int> n_set=curr_set;
        curr_set.push_back(nums[i]);
        generate_subset(i+1,n,nums,curr_set,subsets);
        generate_subset(i+1,n,nums,n_set,subsets);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> curr_set;
        generate_subset(0,nums.size(),nums,curr_set,subsets);
        int ans=0;
        for(auto &it:subsets){
            int xr=0;
            // cout<<"hello";
            for(auto &it2:it){
                // cout<<it2<<" ";
                xr^=it2;
            }
            ans+=xr;
        }
        return ans;
    }
};