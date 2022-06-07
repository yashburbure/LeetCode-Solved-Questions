class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> sorted(m+n);
        int i=0;
        int k=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                sorted[k]=nums1[i];
                i++;
            }
            else{
                sorted[k]=nums2[j];
                j++;
            }
            k++;
        }
        while(i<m){
            sorted[k]=nums1[i];
            i++;k++;
        }
        while(j<n){
            sorted[k]=nums2[j];
            j++;k++;
        }
        nums1.resize(m+n,0);
        for(int i=0;i<m+n;i++){
            nums1[i]=sorted[i];
        }
    }
};