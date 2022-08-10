class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> freq;
        int ans=0,curr_ans;
        const int M=1e9+7;
        int ct,temp;
        for(int i=0;i<arr.size();i++){
            ct=1;
            for(int j=2;j<=sqrt(arr[i]);j++){
                if(arr[i]%j==0){
                    temp=(freq[j]*1ll*freq[arr[i]/j])%M;
                    if(j!=arr[i]/j) temp=(2ll*temp)%M;
                    ct=(ct+0ll+temp)%M;
                }
            }
            ans=(ans+0ll+ct)%M;
            freq[arr[i]]=ct;
        }
        return ans;
    }
};