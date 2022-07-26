class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int mn_a[n],mn_b[n];
        mn_a[0]=nums[0];
        for(int i=1;i<n;i++){
            mn_a[i]=min(mn_a[i-1],nums[i]);
        }
        mn_b[n-1]=nums[n-1];
        set<int> st;
        st.insert(nums[n-1]);
        for(int i=n-2;i>=2;i--){
            st.insert(nums[i]);
            auto it=st.upper_bound(mn_a[i-2]);
            if(it==st.end()){
                mn_b[i]=INT_MIN;
            }
            else{
                mn_b[i]=*it;
            }
        }
        int a,b,c;
        for(int i=1;i<n-1;i++){
            a=mn_a[i-1];
            b=mn_b[i+1];
            c=nums[i];
            if(a<b && b<c){
                return true;
            }
        }
        return false;
    }
};