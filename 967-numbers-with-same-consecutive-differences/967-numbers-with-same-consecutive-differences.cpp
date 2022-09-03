class Solution {
public:
    
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        set<int> st;
        vector<int> ans;
        for(int i=1;i<10;i++) q.push(i);
        int tp,gt,ls;
        int bits,nn;
        while(q.size()){
            tp=q.front();q.pop();
            gt=tp%10+k;
            ls=tp%10-k;
            if(gt<=9){
                nn=tp*10+gt;
                bits=log10(nn)+1;
                if(bits==n) st.insert(nn);
                else q.push(nn);
            }
            if(ls>=0){
                nn=tp*10+ls;
                bits=log10(nn)+1;
                if(bits==n) st.insert(nn);
                else q.push(nn);
            }
        }
        for(auto &it:st) ans.push_back(it);
        return ans;
    }
};