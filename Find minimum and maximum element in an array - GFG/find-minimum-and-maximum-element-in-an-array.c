// { Driver Code Starts
// Initial Template for C

#include <stdio.h>

struct pair {
    long long int min;
    long long int max;
};

struct pair getMinMax(long long int arr[], long long int n) ;

int main() {
    long long int t, n, a[100002], i;
    struct pair minmax;

    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);

        for (i = 0; i < n; i++) scanf("%lld", &a[i]);
        minmax = getMinMax(a, n);
        printf("%lld %lld\n", minmax.min, minmax.max);
    }
    return 0;
}// } Driver Code Ends

int min(long long int a,long long b){
    if(a>b) return b;
    return a;
}
int max(long long int a,long long b){
    if(a>b) return a;
    return b;
}
// User function Template for C
struct pair getMinMax(long long int arr[], long long int n) {
    struct pair min_max={1e18,-1e18};
    for(int i=0;i<n;i++){
        min_max.min=min(min_max.min,arr[i]);
        min_max.max=max(min_max.max,arr[i]);
    }
    return min_max;
}