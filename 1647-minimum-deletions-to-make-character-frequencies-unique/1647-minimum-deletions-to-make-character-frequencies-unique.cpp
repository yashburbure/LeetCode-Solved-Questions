class Solution {
public:
    int minDeletions(string s) {
        int freq[26]={0};
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        priority_queue<int,vector<int>> q;
        for(int i=0;i<26;i++){
            if(freq[i])
                q.push(freq[i]);
        }
        map<int,bool> mp;
        int ans=0;
        while(q.size()){
            int top=q.top();
            q.pop();
            if(mp.find(top)==mp.end()){
                mp[top]=1;
            }
            else{
                auto front=*mp.begin();
                int nnum=front.first-1;
                ans+=top-nnum; 
                if(nnum){
                    mp[nnum]=1;  
                }
            }
        }
        return ans;
    }
};