class Solution {
public:
    bool is_palin(string s,int i,int j){
        while(1){
            if(i>=j ) return 1;
            if(s[i]==s[j]){
                i++;j--;
                continue;
            }
            return 0;
        }
    }
    bool validPalindrome(string s) {
        int n=s.length();
        bool is_one_used=0;
        int lim=n/2;
        int i=0;
        int j=n-1;
        while(i<=lim){
            if(i>=j) break;
            if(s[i]==s[j]){
                i++;j--;
                continue;
            }
            else{
                if(is_palin(s,i+1,j)) return 1;
                else if(is_palin(s,i,j-1)) return 1;
                return 0;
            }
        }
        return 1;
    }
};