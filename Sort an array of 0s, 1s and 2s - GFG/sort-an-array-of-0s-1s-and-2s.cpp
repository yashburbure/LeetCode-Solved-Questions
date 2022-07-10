// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int nums[], int n)
    {
        int st=0;
        int end=n-1;
        int curr=0;
        while(curr<=end){
            if(nums[curr]==0){
                swap(nums[st],nums[curr]);
                st++;
                curr++;
            }
            else if(nums[curr]==2){
                swap(nums[end],nums[curr]);
                end--;
            }
            else curr++;
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends