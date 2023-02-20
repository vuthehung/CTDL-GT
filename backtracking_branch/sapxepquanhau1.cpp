#include<bits/stdc++.h>
using namespace std;
int n, a[100], xuoi[100], nguoc[100], cnt = 0; // mang 1chieu a: luu index la hang va gia tri a[] la cot
void init() {
    cin >> n;
    for(int i = 1; i < 100; i++) {
        a[i] = xuoi[i] = nguoc[i] = 1;
    }
    cnt = 0;
}
void b_t(int i) {
    for(int j = 1; j <= n; j++) {
        if(a[j] && xuoi[i - j + n] && nguoc[i + j - 1]) {
            a[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
            if(i == n) cnt++;
            else b_t(i + 1);
            a[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        init();
        b_t(1);
        cout << cnt << endl;
    }
}