class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        double dp[1001]={0};
        dp[0]=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(i-nums[j]>=0)
                    dp[i]+=dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};