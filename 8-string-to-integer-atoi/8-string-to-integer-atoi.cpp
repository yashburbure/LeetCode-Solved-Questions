class Solution {
public:
    int myAtoi(string& s) {
        char ch=' ';
        int i=0;
        long long ans=0;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='+' || s[i]=='-'){
            ch=s[i];
            i++;
        }
        for(i=i;i<s.length() && (s[i]>='0' && s[i]<='9');i++){
            ans=(10ll*ans)+s[i]-'0';
            if(ans>=INT_MAX) break;
        }
        if(ch=='-'){
            ans=-ans;
            if(ans<INT_MIN) ans=INT_MIN;
        }
        else{
            if(ans>INT_MAX) ans=INT_MAX;
        }
        return ans;
    }
};