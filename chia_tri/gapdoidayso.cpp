#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll find(ll n, ll k) {
	if(k % 2 == 1) return 1;
	ll tmp = pow(2, n - 1);
	if(k == tmp) return n;
	else if(k < tmp) {
		return find(n - 1, k);
	}else {
		return find(n - 1, k - tmp);
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		ll n, k; cin >> n >> k;
		cout << find(n, k) << endl;
	}
}
