#include<bits/stdc++.h>
using namespace std;

int n, m, ans	;
vector<int> adj[100];
bool makr[100][100];

void inp() {
	for(int i = 0; i < n; i++) adj[i].clear();
	ans = 0;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
void dfs(int u, int cnt) {
	for(int v : adj[u]) {
		if(!makr[u][v] && !makr[v][u]) {
			makr[u][v] = makr[v][u] = true;
			dfs(v, cnt + 1);
			makr[u][v] = makr[v][u] = false;
		}
	}
	ans = max(ans, cnt);
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		for(int i = 0; i < n; i++) {
			memset(makr, false, sizeof(makr));
			dfs(i, 0);
		}
		cout << ans << endl;
	}
}
