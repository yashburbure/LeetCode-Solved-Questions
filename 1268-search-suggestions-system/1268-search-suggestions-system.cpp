class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& pro, string sw) {
        sort(pro.begin(),pro.end());
        vector<vector<string>> ans;
        int elefil=0;
        vector<string> cur_ans;
        string sub="";
        string pre;
        for(int i=0;i<sw.length();i++){
            sub.push_back(sw[i]);
            for(int j=0;j<pro.size();j++){
                pre=pro[j].substr(0,i+1);
                if(pre==sub){
                    elefil++;
                    cur_ans.push_back(pro[j]);
                }
                if(elefil==3) break;
            }
            elefil=0;
            ans.push_back(cur_ans);
            cur_ans.clear();
        }
        return ans;
    }
};