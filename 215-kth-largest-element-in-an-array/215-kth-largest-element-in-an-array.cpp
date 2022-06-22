class Solution {
public:
    int findKthLargest(vector<int>& nums, int& k) {
        priority_queue<int,vector<int>> q;
        int i;
        for(i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        i=1;
        while(i<k){
            q.pop();
            i++;
        }
        return q.top();
    }
};