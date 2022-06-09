class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int lo=0,hi=numbers.size()-1;
        int sum;
        while(hi-lo>1){
            sum=numbers[lo]+numbers[hi];
            if(sum==target){
                break;
            }
            else if(sum>target) hi--;
            else lo++;
        }
        ans.push_back(lo+1);
        ans.push_back(hi+1);
        return ans;
    }
};