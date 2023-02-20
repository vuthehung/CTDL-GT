#include<bits/stdc++.h>
using namespace std;

int n, m, u;
vector<int> adj[1001];
vector<pair<int, int> > tree;
bool used[1001];

void inp() {
	for(int i = 1; i <= n; i++) adj[i].clear();
	tree.clear();
	cin >> n >> m >> u;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(used, false, sizeof(used));
}
void bfs(int u) {
	queue<int> q;
	q.push(u);
	used[u] = true;
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int x : adj[v]) {
			if(!used[x]) {
				tree.push_back({v, x});
				q.push(x);
				used[x] = true;
			}
		}
	}
}
void spanning_tree() {
	bfs(u);
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
	}
}
