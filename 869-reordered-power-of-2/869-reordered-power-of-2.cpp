class Solution {
public:
    bool reorderedPowerOf2(int& n) {
        unordered_map<string,bool> powTwo;
        long int no=1;
        string s;
        while(no<=1e9){
            s=to_string(no);
            sort(s.begin(),s.end());
            powTwo[s]=true;
            no=no*2;
        }
        s=to_string(n);
        sort(s.begin(),s.end());
        return powTwo[s];
    }
};