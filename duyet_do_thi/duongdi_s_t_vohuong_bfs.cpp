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
void bfs(int u) {
	queue<int> q;
	q.push(u);
	used[u] = true;
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int e : adj[v]) {
			if(!used[e]) {
				used[e] = true;
				q.push(e);
				parent[e] = v;
			}
		}
	}
}
void path_bfs() {
	memset(used, false, sizeof(used));
	bfs(s);
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
		path_bfs();
		if(ok == 0) cout << "-1\n";
		else {
			for(int x : path) cout << x << " ";
			cout << endl;
		}
	}
}
