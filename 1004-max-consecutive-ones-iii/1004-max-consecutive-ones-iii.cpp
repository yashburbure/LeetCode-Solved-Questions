class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int j=0;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
            }
            while(zero>k){
                if(nums[j]==0) zero--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};