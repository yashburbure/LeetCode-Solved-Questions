class Solution {
public:
    unordered_map<string,int> mp;
    vector<vector<int>> per;
    void make_permutation(vector<int>& nums,int &i,int &n,string& s){
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
            i++;
            make_permutation(nums,i,n,s);
            i--;
            s.pop_back();
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        string s="";
        int i=0;
        int n=nums.size();
        make_permutation(nums,i,n,s);
        return per;
    }
};