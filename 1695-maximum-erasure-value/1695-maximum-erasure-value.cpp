class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int j=0;
        int n=nums.size();
        int ans=0;
        int subarray_sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            subarray_sum+=nums[i];
            while(mp[nums[i]]>1){
                mp[nums[j]]--;
                subarray_sum-=nums[j];
                j++;
            }
            ans=max(ans,subarray_sum);
        }
        return ans;
    }
};