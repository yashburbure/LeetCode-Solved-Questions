class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ZigZagPath;
        int temp=label;
        int ct=0;
        while(label!=1){
            ct++;
            ZigZagPath.push_back(label);
            int NumberOfBits=log2(label);
            int start=(1ll<<NumberOfBits);
            int end=(1ll<<(NumberOfBits+1))-1;
            int mid=(start+end)/2;
            if(label<=mid){
                int positionFromstart=label-start;
                int oppositeElement=end-positionFromstart;
                label=oppositeElement/2;
            }
            else{
                int positionFromend=end-label;
                int oppositeElement=start+positionFromend;
                label=oppositeElement/2;
            }
        }
        ZigZagPath.push_back(1);
        reverse(ZigZagPath.begin(),ZigZagPath.end());
        return ZigZagPath;
    }
};