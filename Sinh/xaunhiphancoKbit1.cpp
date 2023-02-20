#include<bits/stdc++.h>
using namespace std;
int n, k, a[17], ok;
void ktao() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) a[i] = 0;
}
void sinh() {
    int i = n;
    while(i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if(i == 0) ok = 0;
    else a[i] = 1;
}
bool check() {
    int cnt1= 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 1) cnt1++;
    }
    if(cnt1 == k) return true;
    return false;
}
int main() {
    int t; cin >> t;
    while(t--) {
        ktao();
        ok = 1;
        while(ok) {
            if(check()) {
                for(int i = 1; i <= n; i++) cout << a[i];
                cout << endl;
            }
            sinh();
        }
    }
}
//quay lui
// #include<bits/stdc++.h>
// using namespace std;
// int n, k, a[17], ok;
// void ktao() {
//     cin >> n >> k;
//     for(int i = 1; i <= n; i++) a[i] = 0;
// }
// bool check() {
//     int cnt1= 0;
//     for(int i = 1; i <= n; i++) {
//         if(a[i] == 1) cnt1++;
//     }
//     if(cnt1 == k) return true;
//     return false;
// }
// void b_t(int i) {
//     for(int j = 0; j <= 1; j++) {
//         a[i] = j;
//         if(i == n) {
//             if(check()) {
//                 for(int l = 1; l <= n; l++) {
//                     cout << a[l];
//                 }
//                 cout << endl;
//             }
//         }else b_t(i + 1);
//     }
// }
// int main() {
//     int t; cin >> t;
//     while(t--) {
//         ktao();
//         b_t(1);
//     }
// }