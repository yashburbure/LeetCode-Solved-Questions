class Solution {
public:
    string countAndSay(int n) {
        string previousAns="1";
        string currAns;
        for(int i=2;i<=n;i++){
            int ct=1;
            char ch=previousAns[0];
            for(int j=1;j<previousAns.length();j++){
                if(previousAns[j]==ch){
                    ct++;
                }
                else{
                    currAns+=to_string(ct)+ch;
                    ct=1;
                    ch=previousAns[j];
                }
            }
            currAns+=to_string(ct)+ch;
            previousAns=currAns;
            currAns="";
        }
        return previousAns;
    }
};