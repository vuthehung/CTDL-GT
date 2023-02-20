#include<bits/stdc++.h>
using namespace std;

int ok;
int n, m;
int truoc[1001];
vector<int> adj[1001];
vector<int> res;
bool used[1001];

void init() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		adj[i].clear();
	}
	res.clear();
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;	
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
void dfs(int u) {
	used[u] = true;
	for(int x : adj[u]) {
		if(!used[x]) {
			truoc[x] = u;
			dfs(x);
		}
	}
}
void path_s_t_dfs(int s, int t) {
	memset(used, false, sizeof(used));
	dfs(s);
	if(used[t] == false) {
		ok = 0;
	}else {
		ok = 1;
		while(t != s) {
			res.push_back(t);
			t = truoc[t];
		}
		res.push_back(s);
		reverse(res.begin(), res.end());
	}
}
int main() {
	int test; cin >> test;
	while(test--) {
		init();
		int q;
		cin >> q;
		while(q--) {
			int s, t;
			cin >> s >> t;
			path_s_t_dfs(s, t);
			if(ok == 0) {
				cout << "NO\n";
			}else {
				cout << "YES\n";
			}
		}
	}
}
