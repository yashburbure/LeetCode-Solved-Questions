class Solution {
public:
    int dp[30005][2];
    int FindProfit(vector<int>& nums,int ind,int buy){
        if(ind==nums.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int ans=0;
        if(buy){
            ans=max(-nums[ind]+FindProfit(nums,ind+1,0),FindProfit(nums,ind+1,1));
        }
        else{
            ans=max(nums[ind]+FindProfit(nums,ind+1,1),FindProfit(nums,ind+1,0));
        }
        return dp[ind][buy]=ans;
    }
    int maxProfit(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return FindProfit(nums,0,1);
    }
};