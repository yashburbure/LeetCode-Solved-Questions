class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int i,lo,hi,mid;
        vector<pair<int,int>> arr(n);
        vector<int> RightInterval(n);
        
        for(i=0;i<n;i++){
            arr[i]={intervals[i][0],i};
        }
        sort(arr.begin(),arr.end());
        
        for(i=0;i<n;i++){
            lo=0;
            hi=n-1;
            while(hi-lo>1){
                mid=(hi+lo)/2;
                if(arr[mid].first>=intervals[i][1]){
                    hi=mid;
                }
                else{
                    lo=mid+1;
                }
            }
            if(arr[lo].first>=intervals[i][1]){
                RightInterval[i]=arr[lo].second;
            }
            else if(arr[hi].first>=intervals[i][1]){
                RightInterval[i]=arr[hi].second;
            }
            else{
                RightInterval[i]=-1;
            }
        }
        return RightInterval;
    }
};