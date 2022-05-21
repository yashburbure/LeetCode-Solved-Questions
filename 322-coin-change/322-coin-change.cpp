int dp[10002];
class Solution {
public:
    long find_ans(vector<int>& coins,long amount){
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        long ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]>=0)
                ans=min(ans,1l+find_ans(coins,amount-coins[i]));
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        long ans=find_ans(coins,amount);
        return ans==INT_MAX?-1:ans;
        
    }
};