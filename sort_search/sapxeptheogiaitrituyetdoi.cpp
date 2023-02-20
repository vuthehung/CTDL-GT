#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int n, x;
bool cmp(int a, int b) {
    return abs(x - a) < abs(x - b);
}
int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> x;
        for(int i = 0; i < n; i++) cin >> a[i];
        stable_sort(a, a + n, cmp); // neu nhieu ptu co cung hieu tri td thi uu tien thu tu.
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
}