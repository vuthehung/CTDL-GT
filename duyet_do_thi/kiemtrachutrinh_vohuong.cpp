#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool used[1001];

void init() {
	for(int i = 1; i <= n; i++) adj[i].clear();
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

bool chutrinh_dfs(int u, int par) {
	used[u] = true;
	for(int v : adj[u]) {
		if(!used[v]) {
			if(chutrinh_dfs(v, u)) return true;
		}else if(v != par) return true; //day la canh nguoc
	}
	return false;
}
void solve() {
	memset(used, false, sizeof(used));
	for(int i = 1; i <= n; i++) {
		if(!used[i]) {
			if(chutrinh_dfs(i, 0)) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}
int main() {
	int t; cin >> t;
	while(t--) {
		init();
		solve();
	}
}
