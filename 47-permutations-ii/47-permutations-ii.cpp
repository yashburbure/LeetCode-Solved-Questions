class Solution {
public:
    void make_permutation(vector<int>& nums,int i,int n,vector<vector<int>>& per,unordered_map<string,int>& mp,string& s){
        if(i==n){
            if(mp[s]==0){
                per.push_back(nums);
                mp[s]=1;
            }
            return;
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            s.push_back(nums[i]+'0');
            make_permutation(nums,i+1,n,per,mp,s);
            s.pop_back();
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> per;
        unordered_map<string,int> mp;
        string s="";
        make_permutation(nums,0,nums.size(),per,mp,s);
        return per;
    }
};