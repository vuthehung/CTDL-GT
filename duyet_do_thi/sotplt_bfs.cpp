#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool used[1001];

void init() {
	for(int i = 1; i <= n; i++) adj[i].clear();
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
void bfs(int u) {
	queue<int> q;
	q.push(u);
	used[u] = true;
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int t : adj[v]) {
			if(!used[t]) {
				used[t] = true;
				q.push(t);
			}
		}
	}
}
void tplt() {
	memset(used, false, sizeof(used));
	int tplt = 0;
	for(int i = 1; i <= n; i++) {
		if(!used[i]) {
			tplt++;
			bfs(i);
		}
	}
	cout << tplt << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		init();
		tplt();
	}
}
