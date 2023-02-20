#include<bits/stdc++.h>
using namespace std;
int n, k, a[15];
void kt() {
    cin >> n >> k;
    for(int i = 1; i <= k; i++) a[i] = i;
}
void in() {
    for(int i = 1; i <= k; i++) {
        cout << a[i];
    }
    cout << " ";
}
void b_t(int i) {
    for(int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
        if(i == k) {
            in();
        }else b_t(i + 1);
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        kt();
        b_t(1);
        cout << endl;
    }
}