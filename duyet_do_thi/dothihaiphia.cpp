#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
int color[1001];
void inp() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(color, -1, sizeof(color));
}
bool bfs(int u) {
	queue<int> q;
	q.push(u);
	color[u] = 0;
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int x : adj[v]) {
			if(color[x] == -1) {
				color[x] = 1 - color[v];
				q.push(x);
			}else if(color[x] == color[v]) return false;
		}
	}
	return true;
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		bool check = true;
		for(int i = 1; i <= n; i++) {
			if(color[i] == -1) {
				if(!bfs(i)) {
					check = false; break;
				}
			}
		}
		if(check) cout << "YES\n";
		else cout << "NO\n";
	}
}
