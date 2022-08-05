class Solution {
public:
    int combinationSum4(vector<int>& nums, int& target) {
        int dp[1001]={0};
        dp[0]=1;
        long int sum;
        short int i,j,n=nums.size();
        for(i=1;i<=target;i++){
            for(j=0;j<n;j++){
                if(i-nums[j]>=0){
                    sum=0l+dp[i]+dp[i-nums[j]];
                    if(sum>INT_MAX) dp[i]=0;
                    else dp[i]=sum;
                }
            }
        }
        return dp[target];
    }
};