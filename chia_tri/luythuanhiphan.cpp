/* 
a ^ n  =
 1 neu n = 0
 a ^ (n / 2) * a ^ (n / 2)       neu n chan
 a ^ (n / 2) * a ^ (n / 2) * a   neu n le
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll binarypow(ll a, ll b) {
    if(b == 0) return 1;
    ll tmp = binarypow(a, b / 2);
    if(b % 2 == 1) return ((tmp % mod) * (tmp % mod) * (a % mod)) % mod;
    else return ((tmp % mod) * (tmp % mod)) % mod;
}
ll powmod2(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b % 2 == 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        ll n, k; cin >> n >> k;
        cout << powmod2(n, k) << endl;
    }
    return 0;
}
