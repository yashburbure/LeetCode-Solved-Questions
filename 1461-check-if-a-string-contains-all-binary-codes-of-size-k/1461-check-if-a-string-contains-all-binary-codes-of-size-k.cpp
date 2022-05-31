class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<int,bool> mp;
        int n=s.length();
        for(int i=0;i<=n-k;i++){
            int num=0;
            int bit=k-1;
            for(int j=i;j<i+k;j++){
                if(s[j]=='1'){
                    num|=(1<<bit);
                }
                bit--;
            }
            mp[num]=1;
        }
        for(int i=0;i<(1<<k);i++){
            if(mp[i]==0) return 0;
        }
        return 1;
    }
};