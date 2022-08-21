class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int buy=prices[0];
        for(int i=1;i<prices.size();i++){
            ans=max(prices[i]-buy,ans);
            buy=min(buy,prices[i]);
        }
        return ans;
    }
};