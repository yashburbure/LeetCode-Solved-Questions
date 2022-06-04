class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<tuple<int,int,int,int>> pos_ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int lo=j+1;
                int hi=n-1;
                while(lo<hi){
                    long long sum=0ll+nums[lo]+nums[hi]+nums[i]+nums[j];
                    if(sum==target){
                        pos_ans.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                        hi--;
                        lo++;
                    }
                    else if(sum>target) hi--;
                    else lo++;
                }
            }
        }
        set<vector<int>> st;
        for(auto &it:pos_ans){
            st.insert({get<0>(it),get<1>(it),get<2>(it),get<3>(it)});
        }
        for(auto &it:st){
            ans.push_back(it);
        }
        return ans;
    }
};