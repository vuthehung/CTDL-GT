#include<bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
	int n; 
	string s;
	cin >> n >> s;
	map<char, int> mp;
	for(int i = 0; i < s.length(); i++) mp[s[i]]++;
	priority_queue<ll, vector<ll> > q;
	for(auto it : mp) {
		q.push(it.second);
	}
	while(n > 0) {
		ll t = q.top(); q.pop();
		t--;
		q.push(t);
		n--;
	}
	ll ans = 0;
	while(!q.empty()) {
		ll t = q.top(); q.pop();
		ans += t * t;
	}
	cout << ans << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
