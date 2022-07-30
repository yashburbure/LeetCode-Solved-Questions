class Solution {
public:
    void reset(vector<int>& Hsh){
        for(int i=0;i<26;i++) Hsh[i]=0;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n1=words1.size();
        int n2=words2.size();
        int i,j;
        vector<string> Subsets;
        vector<int> Hsh_Max(26,0);
        vector<int> Hsh(26,0);
        for(i=0;i<n2;i++){
            for(j=0;j<words2[i].size();j++){
                Hsh[words2[i][j]-'a']++;
            }
            for(j=0;j<26;j++){
                Hsh_Max[j]=max(Hsh_Max[j],Hsh[j]);
            }
            reset(Hsh);
        }
        for(i=0;i<n1;i++){
            for(j=0;j<words1[i].size();j++){
                Hsh[words1[i][j]-'a']++;
            }
            bool flag=true;
            for(j=0;j<26;j++){
                if(Hsh[j]<Hsh_Max[j]){
                    flag=false;break;
                }
            }
            if(flag){
                Subsets.push_back(words1[i]);
            }
            reset(Hsh);
        }
        return Subsets;
    }
};