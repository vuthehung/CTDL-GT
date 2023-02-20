#include<bits/stdc++.h>
using namespace std;
int n, k, s, ok, res = 0;
int a[100];
// void init() {
//     ok = 1;
//     cin >> n >> k >> s;
//     for(int i = 1; i <= k; i++) {
//         a[i] = i;
//     }
// }
// void sinh() {
//     int i = k;
//     while(i >= 1 && a[i] == n - k + i) i--;
//     if(i == 0) ok = 0;
//     else {
//         a[i]++;
//         for(int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
//     }
// }
// void check() {
//     int sum = 0;
//     for(int i = 1; i <= k; i++) {
//         sum += a[i];
//     }
//     if(sum == s) res++;
// }
void ql(int i) { // dung quay lui
    for(int j = a[i - 1] + 1; j <= n - k + i; j ++) {
        a[i] = j;
        if(i == k) {
            int sum = 0;
            for(int i = 1; i <= k; i++) {
                sum += a[i];
            }
            if(sum == s) res++;
        }else ql(i + 1);
    }
}
int main() {
    while(true) {
        //init();
        cin >> n >> k >> s;
        if(n == 0 && k == 0 && s == 0) break;
        a[0] = 0;
        res = 0;
        ql(1);
        // while(ok) {
        //     // check();
        //     // sinh();
        // }
        cout << res << endl;
    }
}