class Solution {
public:
    int furthestBuilding(vector<int>& hei, int &bri, int &lad) {
        int n=hei.size();
        priority_queue<int,vector<int>,greater<int>> q;
        int ans=0;
        int diff;
        for(int i=1;i<n;i++){
            diff=hei[i]-hei[i-1];
            if(diff>0){
                if(q.size()<lad){
                    q.push(diff);
                }
                else{
                    if(q.size()){
                        if(q.top()<diff){
                            if(bri-q.top()<0){
                                return ans;
                            }
                            else{
                                bri-=q.top();
                                q.pop();
                                q.push(diff);
                            }
                        }
                        else{
                            if(bri-diff<0) return ans;
                            bri-=diff;
                        }
                    }
                    else{
                        if(bri-diff<0){
                            return ans;
                        }
                        bri-=diff;
                    }
                }
            }
            ans=i;
        }
        return ans;
    }
};