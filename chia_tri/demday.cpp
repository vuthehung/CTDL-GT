//Cho so nguy�n duong n. H�y cho biet c� bao nhi�u d�y so nguy�n duong c� tong c�c phan tu trong d�y bang n.
/*
ta co the chia n thanh cac day: n, n - 1, n - 2, ...., 1 phan tu
moi day co cac cach sap xep vi tri cac phan tu khac nhau va = (n-1)C(n-1) = 2^(n - 1)
cong cac day voi nhau
*/ 

#include<bits/stdc++.h>
using namespace std;
#define mod 123456789
#define ll long long

ll powMod(ll a, ll b) {
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
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		cout << powMod(2, n - 1) << endl;
	}
	return 0;
}
