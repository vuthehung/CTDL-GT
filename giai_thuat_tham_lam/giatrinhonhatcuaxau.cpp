#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
	int n;
	string s;
	cin >> n >> s;
	map<char, int> mp;
	for(int i = 0; i < s.length(); i++) {
		mp[s[i]]++;
	}
	priority_queue<ll, vector<ll> > pq;
	for(auto it : mp) {
		pq.push(it.second);
	}
	while(n > 0) {
		ll t = pq.top(); pq.pop();
		t--;
		pq.push(t);
		n--;
	}
	ll ans = 0;
	while(!pq.empty()) {
		ll t = pq.top(); pq.pop();
		ans += t * t;
	}
	cout << ans;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << endl;
	}
}
