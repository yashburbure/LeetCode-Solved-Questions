class Solution {
public:
    int numberOfSteps(int n) {
        int ans=0;
        while(n){
            if(n%2==0){
                ans++;
                n/=2;
            }
            else{
                n--;
                ans++;
            }
        }
        return ans;
    }
};