class Solution {
public:
    int removePalindromeSub(string s) {
        bool flag=1;
        for(int i=0;i<(s.length()/2);i++){
            if(s[i]!=s[s.length()-1-i]){
                flag=0;break;
            }
        }
        if(flag) return 1;
        return 2;
    }
};