class Solution {
public:
    void reverse_str(string& s){
        for(int i=0;i<s.length()/2;i++){
            swap(s[i],s[s.length()-1-i]);
        }
    }
    int reverse(int x) {
        if(x>0){
            string s=to_string(x);
            reverse_str(s);
            long ans=0;
            long f=0;
            for(int i=s.length()-1;i>=0;i--){
                ans=ans+((s[i]-'0')*pow(10,f));
                f++;
            }
            return (ans<=INT_MAX)?ans:0;
        }
        string temp=to_string(x);
        string s=temp.substr(1,temp.length());
        reverse_str(s);
        long ans=0;
        long f=0;
        for(int i=s.length()-1;i>=0;i--){
            ans=ans+((s[i]-'0')*pow(10,f));
            f++;
        }
        ans=-ans;
        return (ans>=INT_MIN)?ans:0;
    }
};