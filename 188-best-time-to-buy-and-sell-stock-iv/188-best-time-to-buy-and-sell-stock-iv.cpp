class Solution {
public:
    int dp[1005][2][101];
    int FindProfit(vector<int>& prices,int ind,int buy,int transaction,int& k){
        if(ind==prices.size()) return 0;
        if(transaction==k) return 0;
        if(dp[ind][buy][transaction]!=-1) return dp[ind][buy][transaction];
        int ans;
        if(buy){
            ans=max(-prices[ind]+FindProfit(prices,ind+1,0,transaction,k),
                   FindProfit(prices,ind+1,1,transaction,k));
        }
        else{
            ans=max(prices[ind]+FindProfit(prices,ind+1,1,transaction+1,k),
                   FindProfit(prices,ind+1,0,transaction,k));
        }
        return dp[ind][buy][transaction]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return FindProfit(prices,0,1,0,k);
    }
};