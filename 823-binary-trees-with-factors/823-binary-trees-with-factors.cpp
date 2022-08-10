class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,long int> freq;
        long int ans=0,curr_ans;
        const long int M=1e9+7;
        long long temp;
        for(int i=0;i<arr.size();i++){
            ans=(ans+1)%M;
            freq[arr[i]]=1;
            for(int j=2;j<=sqrt(arr[i]);j++){
                if(arr[i]%j==0){
                    if(arr[i]/j!=j){
                        temp=(freq[j]*1ll*freq[arr[i]/j])%M;
                        temp=(2*temp)%M;
                        ans=(ans+temp)%M;
                        freq[arr[i]]=(freq[arr[i]]+temp)%M;
                    }
                    else{
                        temp=(freq[j]*1ll*freq[arr[i]/j])%M;
                        ans=(ans+temp)%M;
                        freq[arr[i]]=(freq[arr[i]]+temp)%M;
                    }
                }
            }
        }
        return ans;
    }
};