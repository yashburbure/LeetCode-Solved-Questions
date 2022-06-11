class Solution {
public:
    int minOperations(vector<int>& nums, int &x) {
        int n=nums.size();
        int* prefix=new int[n];
        int* suffix=new int[n];
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(i==0) prefix[i]=nums[i];
            else prefix[i]=prefix[i-1]+nums[i];
            if(prefix[i]==x) ans=min(ans,i+1);
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1) suffix[i]=nums[i];
            else suffix[i]=suffix[i+1]+nums[i];
            if(suffix[i]==x) ans=min(ans,n-i);
        }
        for(int i=0;i<n-1;i++){
            int lo=i+1;
            int hi=n-1;
            int mid;
            while(hi-lo>1){
                mid=(lo+hi)/2;
                if(suffix[mid]+prefix[i]>x) lo=mid+1;
                else hi=mid;
            }
            
            if(prefix[i]+suffix[lo]==x) ans=min(ans,i+1+n-lo);
            if(prefix[i]+suffix[hi]==x) ans=min(ans,i+1+n-hi);
        }
        return (ans==INT_MAX)?-1:ans;
    }
};