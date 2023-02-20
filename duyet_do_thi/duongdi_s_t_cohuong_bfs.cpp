#include<bits/stdc++.h>
using namespace std;

int n, m, s, t, ok;
int parent[1001];
vector<int> adj[1001];
vector<int> res;
bool used[1001];

void init() {
	cin >> n >> m >> s >> t;
	for(int i = 1; i <= n; i++) adj[i].clear();
	res.clear();
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
}
void bfs(int u) {
	queue<int> q;
	q.push(u);
	used[u] = true;
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int x : adj[v]) {
			if(!used[x]) {
				q.push(x);
				parent[x] = v;
				used[x] = true;
			}
		}
	}
}
void path_bfs(int s, int t) {
	memset(used, false, sizeof(used));
	bfs(s);
	if(used[t] == false) {
		ok = 0;
	}else {
		ok = 1;
		while(t != s) {
			res.push_back(t);
			t = parent[t];
		}
		res.push_back(s);
		reverse(res.begin(), res.end());
	}
}
int main() {
	int test; cin >> test;
	while(test--) {
		init();
		path_bfs(s, t);
		if(ok == 0) {
			cout << "-1\n";
		}else {
			for(int x : res) cout << x << " ";
			cout << endl;
		}
	}
}
