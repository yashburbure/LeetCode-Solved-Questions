class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo=0,hi=height.size()-1;
        int ans=0;
        while(lo<hi){
            ans=max(ans,(hi-lo)*min(height[lo],height[hi]));
            if(height[lo]<height[hi]) lo++;
            else hi--;
        }
        return ans;
    }
};
