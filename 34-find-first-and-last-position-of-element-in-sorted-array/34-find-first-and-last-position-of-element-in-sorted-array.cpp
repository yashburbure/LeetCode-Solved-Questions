class Solution {
public:
    int lower_bound(vector<int>& nums,int& target){
        int lo=0,hi=nums.size()-1;
        int mid;
        while(hi-lo>1){
            mid=(lo+hi)/2;
            if(nums[mid]<target) lo=mid+1;
            else hi=mid;
        }
        if(nums[lo]>=target) return lo;
        else if(nums[hi]>=target) return hi;
        return -1;
    }
    int upper_bound(vector<int>& nums,int& target){
        int lo=0,hi=nums.size()-1;
        int mid;
        while(hi-lo>1){
            mid=(lo+hi)/2;
            if(nums[mid]<=target) lo=mid+1;
            else hi=mid;
        }
        if(nums[lo]>target) return lo;
        else if(nums[hi]>target) return hi;
        return hi;
    }
    vector<int> searchRange(vector<int>& nums, int &target) {
        if(!nums.size()) return {-1,-1};
        vector<int> ans(2,-1);
        ans[0]=lower_bound(nums,target);
        if(ans[0]!=-1 && nums[ans[0]]==target){
            ans[1]=upper_bound(nums,target);
            if(nums[ans[1]]>target) ans[1]--;
        }
        else ans[0]=-1;
        return ans;
    }
};