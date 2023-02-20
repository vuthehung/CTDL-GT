#include<bits/stdc++.h>
using namespace std;

int n, m, s;
vector<int> adj[1001];
bool used[1001];
void init() {
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
	memset(used, false, sizeof(used));
}
void dfs(int u) {
	cout << u << " ";
	used[u] = true;
	for(int x : adj[u]) {
		if(!used[x]) {
			dfs(x);
			used[x] = true;
		}
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		init();
		dfs(s);
		cout << endl;
		for(int i = 1; i <= n; i++) adj[i].clear();
	}
}
