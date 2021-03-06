class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        int* longestChain=new int[n];
        for(int i=0;i<n;i++) longestChain[i]=1;
        int ans=1;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[words[i].length()].push_back(i);
        }
        int j,k;
        for(int i=2;i<=16;i++){
            for(int &it1:mp[i]){
                for(int &it2:mp[i-1]){
                    j=0;
                    k=0;
                    while(j<i && k<i-1){
                        if(words[it1][j]==words[it2][k]){
                            j++;
                            k++;
                        }
                        else{
                            j++;
                        }
                    }
                    if((j==i || j==i-1) && k==i-1){
                        longestChain[it1]=max(longestChain[it1],longestChain[it2]+1);
                        ans=max(ans,longestChain[it1]);
                    }
                }
            }
        }
        delete[] longestChain;
        return ans;
    }
};