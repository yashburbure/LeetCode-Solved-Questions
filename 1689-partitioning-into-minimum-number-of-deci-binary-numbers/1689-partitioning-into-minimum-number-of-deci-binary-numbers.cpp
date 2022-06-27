class Solution {
public:
    int minPartitions(string& n) {
        char ans=0;
        for(char &ch:n){
            ans=max(ans,ch);
            if(ans=='9') return 9;
        }
        return (ans-'0');
    }
};