#include<bits/stdc++.h>
using namespace std;

int n, pre[1001];
vector<int> adj[1001];
vector<int> leaf; //luu cac node la
bool used[1001];

void inp() {
	for(int i = 1; i <= n; i++) adj[i].clear();
	leaf.clear();
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 2; i <= n; i++) { // khong duyet dinh 1 vi 1 la goc
		if(adj[i].size() == 1) {
			leaf.push_back(i);
		}
	}
}
void dfs(int u) {
	used[u] = true;
	for(int v : adj[u]) {
		if(!used[v]) {
			pre[v] = u;
			dfs(v);
		}
	}
}
void path(int u, int v) {
	memset(used, false, sizeof(used));
	dfs(1);
	vector<int> path;
	while(v != u) {
		path.push_back(v);
		v = pre[v];
	}
	path.push_back(1); // duyet tu goc den cac node la
	reverse(path.begin(), path.end());
	for(int x : path) cout << x << " ";
}
int main() {
	int t; cin >>t;
	while(t--) {
		inp();
		for(int l : leaf) {
			path(1, l);
			cout << endl;
		}
	}
}
