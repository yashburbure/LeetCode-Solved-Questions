class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        set<long int> mset;
        mset.insert(1);
        int sz=0;
        long int curr;
        int i;
        while(mset.size()){
            curr=*mset.begin();
            mset.erase(mset.begin());
            sz++;
            if(sz==n) return curr;
            for(i=0;i<primes.size();i++){
                mset.insert(curr*primes[i]);
            }
        }
        return 9;
    }
};