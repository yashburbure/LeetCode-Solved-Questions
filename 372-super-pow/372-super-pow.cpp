class Solution {
public:
    long long superPow(int a, vector<int>& b) {
        long long etf=1140;
        long long st=0;
        for(int i=0;i<b.size();i++){
            st=(st*10)+b[i];
            st=st%etf;
        }
        long long ans=1;
        while(st){
            if(st&1){
                ans=(ans*1ll*a)%1337;
            }
            a=(a*1ll*a)%1337;
            st>>=1;
        }
        return ans;
    }
};