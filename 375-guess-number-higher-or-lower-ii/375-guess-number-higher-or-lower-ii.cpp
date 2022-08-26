class Solution {
public:
    int dp[201][201];
    int MoneyAmount(int st,int end){
        if(st>=end){
            return 0;
        }
        if(dp[st][end]!=-1){
            return dp[st][end];
        }
        int ans=INT_MAX;
        int ind=st;
        for(int i=st;i<=end;i++){
            ans=min(ans,i+max(MoneyAmount(st,i-1),MoneyAmount(i+1,end)));
        }
        return dp[st][end]=ans;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return MoneyAmount(1,n);
    }
};