#include<bits/stdc++.h>
using namespace std;
int n, x;
int a[1000001];
bool cmp(int a, int b) {
    return abs(x - a) < abs(x - b);
}
int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> x;
        for(int i = 0; i < n; i++) cin >> a[i];
        stable_sort(a, a + n, cmp);
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
}