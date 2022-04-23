class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st=0;
        int end=nums.size()-1;
        int curr=0;
        while(curr<=end){
            if(nums[curr]==0){
                swap(nums[st],nums[curr]);
                st++;
                curr++;
            }
            else if(nums[curr]==2){
                swap(nums[end],nums[curr]);
                end--;
            }
            else curr++;
        }
    }
};