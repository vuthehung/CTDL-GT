#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int> > adj[1001];

void inp() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
	}
}
void bellman_ford(int u) {
	vector<int> d(n + 1, 1e9);
	d[u] = 0;
	for(int i = 0; i < n - 1; i++) {
		for(int u = 1; u <= n; u++) {
			for(auto x : adj[u]) {
				d[x.first] = min(d[x.first], d[u] + x.second);
			}
		}
	}
	bool ok = false;
	for(int u = 1; u <= n; u++) {
		for(auto v : adj[u]) {
			if(d[v.first] > d[u] + v.second) {
				ok = true; break;
			}
		}
	}
	cout << (ok ? "1\n" : "0\n");
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		bellman_ford(1);
		for(int i = 1; i <= n; i++) adj[i].clear();
	}
}
