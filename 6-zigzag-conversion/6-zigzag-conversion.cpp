class Solution {
public:
    string convert(string& s, int& numRows) {
        if(numRows==1) return s;
        vector<string> Rows(numRows,"");
        int CurrRow=0;
        bool flag=true;
        for(int i=0;i<s.length();i++){
            Rows[CurrRow].push_back(s[i]);
            if(CurrRow==0){
                flag=true;
                CurrRow++;
            }
            else if(CurrRow==numRows-1){
                flag=false;
                CurrRow--;
            }
            else if(flag) CurrRow++;
            else CurrRow--;
        }
        string ans="";
        for(int i=0;i<numRows;i++) ans+=Rows[i];
        return ans;
    }
};