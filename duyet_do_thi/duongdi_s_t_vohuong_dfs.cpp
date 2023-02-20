#include<bits/stdc++.h>
using namespace std;

int n, m, s, t, ok;
int parent[1001];
vector<int> adj[1001];
vector<int> path;
bool used[1001];

void init() {
	path.clear();
	memset(parent, 0, sizeof(parent));
	for(int i = 1; i <= n; i++) adj[i].clear();
	cin >> n >> m >> s >> t;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
void dfs(int u) {
	used[u] = true;
	for(int v : adj[u]) {
		if(!used[v]) {
			parent[v] = u;
			dfs(v);
		}
	}
}
void path_dfs() {
	memset(used, false, sizeof(used));
	dfs(s);
	if(!used[t]) {
		ok = 0;
	}else {
		ok = 1;
		while(t != s) {
			path.push_back(t);
			t = parent[t];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		init();
		path_dfs();
		if(ok == 0) cout << "-1\n";
		else {
			for(auto x : path) cout << x << " ";
			cout << endl;
		}
	}
}
