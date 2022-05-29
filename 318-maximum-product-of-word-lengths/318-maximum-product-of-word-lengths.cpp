class Solution {
public:
    int max(int a,int b){
        return (a>b)?a:b;
    }
    int maxProduct(vector<string>& w) {
        int n=w.size();
        vector<int> mask(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<w[i].length();j++){
                int bit=w[i][j]-'a';
                mask[i]|=(1<<bit);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int bit_and=mask[i]&mask[j];
                if(bit_and==0){
                    ans=max(ans,w[i].length()*w[j].length());
                }
            }
        }
        return ans;
    }
};