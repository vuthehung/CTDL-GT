#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100001];
bool used[100001];

void dfs(int u) {
	used[u] = true;
	for(int x : adj[u]) {
		if(!used[x]) {
			used[x] = true;
			dfs(x);
		}
	}
}
void inp() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bool ok = true;
	memset(used, false, sizeof(used));
	dfs(1);
	for(int i = 1; i <= n; i++) {
		if(!used[i]) {
			ok = false; break;
		}
	}
	if(ok) cout << "YES\n";
	else cout << "NO\n";
	for(int i = 1; i <= n; i++) adj[i].clear();
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
	}
}
