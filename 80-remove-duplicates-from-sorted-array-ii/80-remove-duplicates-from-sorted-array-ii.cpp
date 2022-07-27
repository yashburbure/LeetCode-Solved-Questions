class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=0;
        int previous=-1;
        int ct=0;
        int ptr=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==previous){
                ct++;
            }
            else{
                previous=nums[i];
                ct=0;
            }
            if(ct<=1){
                nums[ptr]=nums[i];
                ptr++;
                ans++;
            }
        }
        return ans;
    }
};