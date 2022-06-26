class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int suffix[n+1];
        suffix[0]=0;
        int ans=0;
        for(int i=0;i<k;i++){
            suffix[i+1]=card[n-1-i]+suffix[i];
            ans=max(ans,suffix[i+1]);
        }
        int pre_sum=0;
        for(int i=0;i<k;i++){
            pre_sum+=card[i];
            ans=max(ans,pre_sum+suffix[k-i-1]);
        }
        return ans;
    }
};