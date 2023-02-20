#include<bits/stdc++.h>
using namespace std;
//O(nlogn)
// tim cross sum. tim tong lien tiep nam o mid va 2 ben mid.
int find(int a[], int l, int m, int r) {
    int sum1 = -1e9, sum2 = -1e9, sum = 0;
    for(int i = m; i >= l; i--){
        sum += a[i];
        sum1 = max(sum1, sum);
    }
    sum = 0;
    for(int i = m + 1; i <= r; i++) {
        sum += a[i];
        sum2 = max(sum2, sum);
    }
    return sum1 + sum2;
} 
int maxSum(int a[], int l, int r) {
    if(l == r) return a[l];
    int m = (l + r) / 2;
    int sumLeft = maxSum(a, l, m);
    int sumRight = maxSum(a, m + 1, r);
    int cross = find(a, l, m, r);
    return max(sumLeft, max(sumRight, cross));
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << maxSum(a, 0, n - 1) << endl;
    }
}