class Solution {
public:
    static void inputOutput(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    vector<int> findSubstring(string &s, vector<string>& words) {
        inputOutput();
        unordered_map<string,int> Count;
        unordered_map<string,int> mp;
        int len=words[0].length();
        vector<int> ans;
        int left,CountWord;
        for(int i=0;i<words.size();i++){
            Count[words[i]]++;
        }
        int i=0,j;
        while((s.length()-i)>=words.size()*len){
            mp.clear();
            CountWord=0;
            for(j=i;j<=s.length()-len;j+=len){
                string New=s.substr(j,len);
                if(Count.count(New)==0){
                    i++;
                    break;
                }
                else if(mp[New]>=Count[New]){
                    i++;
                    break;
                }
                else{
                    mp[New]++;
                    CountWord++;
                }
                if(CountWord==words.size()){
                    ans.push_back(i);
                }
            }
            if(j>s.length()-len) i++;
        }
        return ans;
    }
};