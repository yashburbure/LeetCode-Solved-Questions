class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans=(1ll*dividend)/(1ll*divisor);
        cout<<ans<<endl;
        if(ans>INT_MAX) ans=INT_MAX;
        if(ans<INT_MIN) ans=INT_MIN;
        return ans;
    }
};