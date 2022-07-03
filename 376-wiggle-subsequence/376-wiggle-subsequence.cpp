class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        short int n=nums.size();
        int dp_p[n],dp_n[n];
        int i,j;
        int ans=1;
        for(i=0;i<n;i++){
            dp_p[i]=1;
            dp_n[i]=1;
            for(j=i-1;j>=0;j--){
                if(nums[j]>nums[i]){
                    dp_n[i]=max(dp_n[i],1+dp_p[j]);
                }
                else if(nums[j]<nums[i]){
                    dp_p[i]=max(dp_p[i],1+dp_n[j]);
                }
            }
            ans=max(ans,dp_p[i]);
            ans=max(ans,dp_n[i]);
        }
        return ans;
    }
};