class Solution {
public:
    int dp[100004][2][2];
    int FindProfit(vector<int>& prices,int ind,int buy,int transaction){
        if(ind==prices.size()) return 0;
        if(transaction==2) return 0;
        if(dp[ind][buy][transaction]!=-1) return dp[ind][buy][transaction];
        int ans;
        if(buy){
            ans=max(-prices[ind]+FindProfit(prices,ind+1,0,transaction),
                   FindProfit(prices,ind+1,1,transaction));
        }
        else{
            ans=max(prices[ind]+FindProfit(prices,ind+1,1,transaction+1),
                   FindProfit(prices,ind+1,0,transaction));
        }
        return dp[ind][buy][transaction]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return FindProfit(prices,0,1,0);
    }
};