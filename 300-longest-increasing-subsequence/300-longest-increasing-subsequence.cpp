class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> lis(n+1,INT_MAX);
        lis[0]=INT_MIN;
        int ans=0;
        int it;
        for(int i=0;i<n;i++){
            it=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
            ans=max(ans,it);
            if(nums[i]<lis[it] && lis[it-1]<nums[i]){
                lis[it]=nums[i];
            }
        }
        return ans;
    }
};