class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        set<pair<int,int>,greater<pair<int,int>>> st;
        int n=nums.size();
        st.insert({nums[0],0});
        unordered_map<int,int> mp;
        mp[0]=nums[0];
        for(int i=1;i<n;i++){
            if(i-k-1>=0)
                st.erase(st.find({mp[i-k-1],i-k-1}));
            mp[i]=nums[i]+(*st.begin()).first;
            st.insert({nums[i]+(*st.begin()).first,i});   
        }
        return mp[n-1];
    }
};