class Solution {
public:
    unordered_map<string,bool> dp;
    bool check(string s1,string s2,string s3,int p1,int p2,int p3,int l1,int l2,int l3){
        if(p3==l3){
            return (p1==l1&&p2==l2);
        }
        string key=to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
        if(dp.find(key)!=dp.end()) return dp[key];
        if(s3[p3]==s1[p1]&&s3[p3]==s2[p2]){
            dp[key]=check(s1,s2,s3,p1+1,p2,p3+1,l1,l2,l3);
            return dp[key]=dp[key]||check(s1,s2,s3,p1,p2+1,p3+1,l1,l2,l3);
        }
        else if(s3[p3]==s1[p1]){
            return dp[key]=check(s1,s2,s3,p1+1,p2,p3+1,l1,l2,l3);
        }
        else if(s3[p3]==s2[p2]){
            return dp[key]=check(s1,s2,s3,p1,p2+1,p3+1,l1,l2,l3);
        }
        return dp[key]=0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.length();
        int len2=s2.length();
        int len3=s3.length();
        if(len1+len2!=len3) return 0;
        return check(s1,s2,s3,0,0,0,len1,len2,len3);
    }
};