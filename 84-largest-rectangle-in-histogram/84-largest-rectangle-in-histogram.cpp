class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int n=heights.size();
        int minHeightLeft[n];
        int minHeightRight[n];
        for(int i=0;i<heights.size();i++){
            while(st.size() && st.top().first>=heights[i]){
                st.pop();
            }
            if(st.size()) minHeightLeft[i]=st.top().second;
            else minHeightLeft[i]=-1;
            st.push({heights[i],i});
        }
        while(st.size()) st.pop();
        for(int i=heights.size()-1;i>=0;i--){
            while(st.size() && st.top().first>=heights[i]) st.pop();
            if(st.size()) minHeightRight[i]=st.top().second;
            else minHeightRight[i]=n;
            st.push({heights[i],i});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(minHeightRight[i]-minHeightLeft[i]-1)*heights[i]);
        }
        return ans;
    }
};