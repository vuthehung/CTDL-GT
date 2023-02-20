#include<bits/stdc++.h>
using namespace std;

const int INF = (int) 1e9 + 1;
int n, m, s;
vector<pair<int, int> > adj[1001];

void inp() {
	for(int i = 1; i <= n; i++) adj[i].clear();
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({w, y});
		adj[y].push_back({w, x});
	}
}
void dijkstra() {
	vector<int> d(n + 1, INF);
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push({0, s});
	while(!q.empty()) {
		pair<int, int> t = q.top(); q.pop();
		int len = t.first, u = t.second;
		if(len > d[u])
			continue;
		for(auto it: adj[u]) {
			if(d[it.second] > d[u] + it.first) {
				d[it.second] = d[u] + it.first;
				q.push({d[it.second], it.second});
			}
		}
	}
	for(int i = 1;i <= n; i++) {
		cout << d[i] << " ";
	}
	cout << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		dijkstra();
	}
}
