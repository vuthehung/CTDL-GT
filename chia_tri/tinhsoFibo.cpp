// tinh so fibo thu n(n >= 1 ti).
//so fibo thu n = ma tran (Fn+1 Fn)   mu n hay (1 1) mu n.
//                         Fn   Fn-1            1 0 
// ung dung luy thua nhi phan
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void nhanArr(long long a[2][2], ll b[2][2]) {
    long long c[2][2];
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            c[i][j] = 0;
            for(int k = 0; k < 2; k++) {
                c[i][j] += (a[i][k] * b[k][j]) % mod;
                c[i][j] % mod;
            }
        }
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            a[i][j] = c[i][j];
        }
    }
}
ll power1(ll a[2][2], ll n) {
    ll res[2][2] = {{1, 0}, {0, 1}};
    while(n) {
        if(n % 2 == 1) {
            nhanArr(res, a);
        }
        nhanArr(a, a);
        n /= 2;
    }
    return res[0][1];
}
void power2(ll a[2][2], int n) {
    if(n == 0 || n == 1) return;
    ll tmp[2][2] = {{1, 1}, {1, 0}};
    power2(a, n / 2);
    nhanArr(a, a);
    if(n % 2 == 1) nhanArr(a, tmp);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ll a[2][2] = {{1, 1}, {1, 0}};
    //cout << power1(a, n) << endl;
    power2(a, n);
    cout << a[0][1];
}