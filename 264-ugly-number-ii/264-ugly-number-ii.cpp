class Solution {
public:
    int nthUglyNumber(int n) {
        int ct=0;
        set<long long> st;
        st.insert(1);
        while(ct!=n){
            ct++;
            long long curr=*st.begin();
            if(ct==n) return curr;
            st.erase(st.begin());
            if(ct==n) return curr;
            st.insert(curr*2);
            st.insert(curr*3);
            st.insert(curr*5);
        }
        return 0;
    }
};