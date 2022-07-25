class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int mx_mountain=arr[0];
        int index=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mx_mountain){
                mx_mountain=arr[i];
                index=i;
            }
        }
        return index;
    }
};