class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans=0;
        for(char &ch:stones){
            bool flag=0;
            for(char &ch1:jewels){
                if(ch1==ch){
                    flag=1;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};