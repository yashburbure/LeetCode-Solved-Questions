class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        int ind;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1) return 1;
        int temp=nums[ind];
        bool flag=1;
        if(ind==0) nums[ind]=1e-5;
        else nums[ind]=nums[ind-1];
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                flag=0;break;
            }
        }
        if(flag) return 1;
        nums[ind]=temp;
        if(ind+1==n-1){
            nums[ind+1]=1e5; 
        }
        else{
             nums[ind+1]=nums[ind+2];
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) return 0;
        }
        return 1;
    }
};