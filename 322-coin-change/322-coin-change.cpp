class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long dp[amount+1];
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            dp[i]=INT_MAX;
            for(auto &it:coins){
                if(i>=it)
                    dp[i]=min(dp[i],1+dp[i-it]);
            }
        }
        return (dp[amount]==INT_MAX)?-1:dp[amount];
    }
};