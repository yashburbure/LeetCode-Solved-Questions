class Solution {
public:
    int minPartitions(string& n) {
        char ans=0;
        for(char &ch:n){
            ans=max(ans,ch);
        }
        return (ans-'0');
    }
};