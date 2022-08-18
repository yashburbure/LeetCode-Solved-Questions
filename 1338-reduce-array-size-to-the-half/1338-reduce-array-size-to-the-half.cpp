class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>> nArr;
        for(auto &it:mp){
            nArr.push_back({it.second,it.first});
        }
        sort(nArr.begin(),nArr.end(),greater<pair<int,int>>());
        int size=arr.size();
        for(int i=0;i<nArr.size();i++){
            size-=nArr[i].first;
            if(size<=arr.size()/2) return i+1;
        }
        return -1;
    }
};