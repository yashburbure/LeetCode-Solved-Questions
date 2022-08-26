class Solution {
public:
    vector<int> posSet;
    void generateSet(int freq[],int no,int ct){
        if(ct==0){
            posSet.push_back(no);
            return;
        }
        for(int i=0;i<10;i++){
            if(no==0 && i==0) continue;
            if(freq[i]){
                freq[i]--;
                generateSet(freq,no*10+i,ct-1);
                freq[i]++;
            }
        }
    }
    bool reorderedPowerOf2(int n) {
        int freq[10]={0};
        int temp=n;
        int ct=0;
        while(temp){
            ct++;
            int rem=temp%10;
            freq[rem]++;
            temp/=10;
        }
        generateSet(freq,0,ct);
        for(auto &it:posSet){
            while(it%2==0) it=it/2;
            if(it==1) return true;
        }
        return false;
    }
};