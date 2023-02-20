#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> power; // luu 2^x;
void init(ll n) {
	int tmp = log2(n);
	for(int i = 0; i <= tmp; i++) {
		power.push_back((ll)(pow(2, i)));
	}
}
int find(ll k, ll n, ll idx) { // tra ve so 1 o vi tri k
	if(k % 2 == 1) {
		return 1;
	}
	if(k < power[idx]) {
		return find(k, n / 2, idx - 1);
	}else if(k == power[idx]) {
		return n % 2;
	}
	return find(k - power[idx], n / 2, idx - 1);
}
int main() {
	int t; cin >> t;
	while(t--) {
		ll n, l, r;
		init(n);
		cin >> n >> l >> r;
		int ans = 0;
		for(ll i = l; i <= r; i++) {
			ans += find(i, n, power.size() - 1);
		}
		cout << ans << endl;
		power.clear();
	}
}
