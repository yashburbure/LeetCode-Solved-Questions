class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long,vector<long>,greater<long>> q;
        q.push(1);
        int sz=0;
        long curr;
        int i;
        while(q.size()){
            curr=q.top();
            q.pop();
            if(q.size() && curr==q.top()) continue;
            sz++;
            if(sz==n) return curr;
            for(i=0;i<primes.size();i++){
                q.push(curr*primes[i]);
            }
        }
        return -1;
    }
};