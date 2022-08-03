class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> Path;
        int Point=label;
        int OppositePoint,NumberOfbits,start,end,mid;
        while(Point!=1){
            Path.push_back(Point);
            NumberOfbits=log2(Point)+1;
            start=(1ll<<NumberOfbits)-1;
            end=(1ll<<NumberOfbits)/2;
            mid=(start+end)/2;
            if(Point>=mid){
                Point=(1ll<<(NumberOfbits-1))+(1ll<<(NumberOfbits))-Point-1;
            }
            else{
                Point=(1ll<<NumberOfbits)-(Point-(1ll<<(NumberOfbits-1)))-1;
            }
            Point=Point/2;
            // cout<<Point<<endl;
        }
        Path.push_back(1);
        reverse(Path.begin(),Path.end());
        return Path;
    }
};