class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int& target) {
        int n=nums.size();
        vector<pair<int,int>> narr(n);
        for(int i=0;i<n;i++){
            narr[i]={nums[i],i};
        }
        sort(narr.begin(),narr.end());
        int hi=n-1;
        int lo=0;
        int sum;
        while(hi>lo){
            sum=narr[hi].first+narr[lo].first;
            if(sum==target) return {narr[lo].second,narr[hi].second};
            else if(sum>target) hi--;
            else lo++;
        }
        return {};
    }
};