class Solution {
public:
    vector<vector<int>> per;
    void make_permutation(vector<int>& nums,int &i,int &n){
        if(i==n){
            per.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            i++;
            make_permutation(nums,i,n);
            i--;
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        make_permutation(nums,i,n);
        return per;
    }
};