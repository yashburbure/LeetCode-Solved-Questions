class Solution {
public:
    long double fact(int a){
        long double ans=1;
        for(int i=2;i<=a;i++){
            ans*=(i*1.0);
        }
        return ans;
    }
    long double nCr(int a,int b){
        long double ans=fact(a);
        ans/=fact(b);
        ans/=fact(a-b);
        return ans;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        ans[0]=1;
        for(int i=1;i<=rowIndex;i++){
            ans[i]=nCr(rowIndex,i)+1e-9;
        }
        return ans;
    }
};