class Solution {
public:
    int fib(int& n) {
        int fi=0,se=1;
        if(n==0) return 0;
        if(n==1) return 1;
        int sum;
        for(int i=2;i<=n;i++){
            sum=fi+se;
            fi=se;
            se=sum;
        }
        return se;
    }
};