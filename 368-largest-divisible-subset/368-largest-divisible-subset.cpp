class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp[n];
        for(int i=0;i<n;i++){
            int msteffidx=i;
            int curr_sz=1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(dp[j].size()>=curr_sz){
                        curr_sz=dp[j].size()+1;
                        msteffidx=j;
                    }
                }
            }
           dp[i]=dp[msteffidx];
           dp[i].push_back(nums[i]);
        }
        int idx=0;
        int sz=0;
        for(int i=0;i<n;i++){
            if(dp[i].size()>sz){
                sz=dp[i].size();
                idx=i;
            }
        }
        return dp[idx];
    }
};