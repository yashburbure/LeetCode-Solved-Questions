class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    int minOperations(vector<int>& nums, int &x) {
        int n=nums.size();
        int* suffix=new int[n];
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(i==n-1) suffix[i]=nums[i];
            else suffix[i]=suffix[i+1]+nums[i];
            if(suffix[i]==x) ans=min(ans,n-i);
        }
        int previous_sum=0;
        int lo,hi,mid;
        for(int i=0;i<n-1;i++){
            previous_sum+=nums[i];
            lo=i+1;
            hi=n-1;
            while(hi-lo>1){
                mid=(lo+hi)/2;
                if(suffix[mid]+previous_sum>x) lo=mid+1;
                else hi=mid;
            }
            if(previous_sum==x) ans=min(ans,i+1);
            if(previous_sum+suffix[lo]==x) ans=min(ans,i+1+n-lo);
            if(previous_sum+suffix[hi]==x) ans=min(ans,i+1+n-hi);
        }
        delete[] suffix;
        previous_sum+=nums[n-1];
        if(previous_sum==x) ans=min(ans,n);
        return (ans==INT_MAX)?-1:ans;
    }
};