class Solution {
public:
    int numJewelsInStones(string j, string s) {
        int ans=0;
        long long mask=0;
        for(char &ch:j){
            if(ch>='a' && ch<='z'){
                mask|=(1ll<<(ch-'a'));
            }
            else{
                mask|=(1ll<<(ch-'A'+26));
            }
        }
        for(char &ch:s){
            if(ch>='a' && ch<='z'){
                if(mask&(1ll<<(ch-'a'))) ans++;
            }
            else{
                if(mask&(1ll<<(ch-'A'+26))) ans++;
            }
        }
        return ans;
    }
};