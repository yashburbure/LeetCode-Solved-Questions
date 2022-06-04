class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int lo=j+1;
                int hi=n-1;
                while(lo<hi){
                    long long sum=0ll+nums[lo]+nums[hi]+nums[i]+nums[j];
                    if(sum==target){
                        st.insert({nums[i],nums[j],nums[lo],nums[hi]});
                        hi--;
                        lo++;
                    }
                    else if(sum>target) hi--;
                    else lo++;
                }
            }
        }
        for(auto &it:st){
            ans.push_back(it);
        }
        return ans;
    }
};