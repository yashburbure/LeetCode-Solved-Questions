class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int j=0;
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(dq.empty()==0 && dq.back()<nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            if((i-j+1)<k){
                continue;
            }
            else{
                ans.push_back(dq.front());
            }
            if(dq.front()==nums[j]){
                dq.pop_front();
            }
            j++;
        }
        return ans;
    }
};