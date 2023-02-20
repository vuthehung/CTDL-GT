#include<bits/stdc++.h>
using namespace std;

int n, m, u;
vector<int> adj[1001];
vector<pair<int, int> > tree;
bool used[1001];

int inp() {
	cin >> n >> m >> u;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(used, false, sizeof(used));
}
void dfs(int u) {
	used[u] = true;
	for(int x : adj[u]) {
		if(!used[x]) {
			tree.push_back({u, x});
			dfs(x);
		}
	}
}
void spanning_tree() {
	dfs(u);
	for(int i = 1; i <= n; i++) {
		if(!used[i]) {
			cout << "-1\n";
			return;
		}
	}
	for(auto it : tree) {
		cout << it.first << " " << it.second << endl;
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		spanning_tree();
		for(int i = 1; i <= n; i++) adj[i].clear();
		tree.clear();
	}
}
