class Solution {
public:
    // int dp[30005][2];
    // int FindProfit(vector<int>& nums,int ind,int buy){
    //     if(ind==nums.size()) return 0;
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     int ans=0;
    //     if(buy){
    //         ans=max(-nums[ind]+FindProfit(nums,ind+1,0),FindProfit(nums,ind+1,1));
    //     }
    //     else{
    //         ans=max(nums[ind]+FindProfit(nums,ind+1,1),FindProfit(nums,ind+1,0));
    //     }
    //     return dp[ind][buy]=ans;
    // }
    int maxProfit(vector<int>& nums) {
        int dp[nums.size()][2];
        int n=nums.size();
        dp[0][0]=0;
        dp[0][1]=-nums[0];
        int ans=0;
        for(int i=1;i<n;i++){
            dp[i][1]=max(dp[i-1][1],-nums[i]+dp[i-1][0]);
            dp[i][0]=max(dp[i-1][0],nums[i]+dp[i-1][1]);
            ans=max(ans,dp[i][0]);
            ans=max(ans,dp[i][1]);
        }
        return ans;
    }
};