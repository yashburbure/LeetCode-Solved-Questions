class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int hi,lo,mid;
        int ans=-1;
        int papers_g,papers_l,papers_e,papers_n;
        for(int i=0;i<=1000;i++){
            auto it1=upper_bound(citations.begin(),citations.end(),i)-citations.begin();
            auto it2=lower_bound(citations.begin(),citations.end(),i)-citations.begin();
            papers_g=n-it1;
            papers_l=it2;
            papers_e=n-papers_g-papers_l;
            if(papers_g>i) continue;
            papers_n=i-papers_g;
            if(papers_n<=papers_e) ans=max(ans,i);
        }
        return ans;
    }
};