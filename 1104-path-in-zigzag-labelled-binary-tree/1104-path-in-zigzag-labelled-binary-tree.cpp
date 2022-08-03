class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<vector<int>> AllLevel;
        for(int i=1;;i++){
            vector<int> CurrLevel;
            bool flag=false;
            int start=(1ll<<(i-1));
            int end=(1ll<<(i))-1;
            for(int j=start;j<=end;j++){
                if(j==label) flag=true;
                CurrLevel.push_back(j);
            }
            if(i%2==0){
                reverse(CurrLevel.begin(),CurrLevel.end());
            }
            AllLevel.push_back(CurrLevel);
            if(flag) break;
        }
        int index=-1;
        for(int i=1;i<AllLevel[AllLevel.size()-1].size();i++){
            if(AllLevel[AllLevel.size()-1][i]==label){
                index=i;
                break;
            }
        }
        int CurrLevel=AllLevel.size()-1;
        vector<int> ZigZagPath;
        int element=label;
        while(element!=1){
            ZigZagPath.push_back(element);
            index=index/2;
            CurrLevel--;
            element=AllLevel[CurrLevel][index];
        }
        ZigZagPath.push_back(1);
        reverse(ZigZagPath.begin(),ZigZagPath.end());
        return ZigZagPath;
    }
};