class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int hi,lo,mid;
        int ans=-1;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[citations[i]]++;
        }
        for(int i=0;i<=1000;i++){
            auto it1=upper_bound(citations.begin(),citations.end(),i)-citations.begin();
            auto it2=lower_bound(citations.begin(),citations.end(),i)-citations.begin();
            int papers_g=n-it1;
            int papers_l=it2;
            int papers_e=freq[i];
            if(papers_g>i) continue;
            // cout<<papers_g<<" "<<papers_l<<" "<<papers_e<<endl;
            int papers_n=i-papers_g;
            if(papers_n<=papers_e) ans=max(ans,i);
        }
        return ans;
    }
};