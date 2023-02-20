#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001], r_adj[1001];
bool used[1001];
stack<int> st;
void init() {
	for(int i = 1; i <= n; i++){
		adj[i].clear();
		r_adj[i].clear();
	}
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		r_adj[y].push_back(x);
	}
}
void dfs1(int u) {
	used[u] = true;
	for(int v : adj[u]) {
		if(!used[v]) {
			used[v] = true;
			dfs1(v);
		}
	}
	st.push(u);
}
void dfs2(int u) {
	used[u] = true;
	for(int v : r_adj[u]) {
		if(!used[v]) {
			used[v] = true;
			dfs2(v);
		}
	}
}
void strongly_connected() {
	memset(used, false, sizeof(used));
	for(int i = 1; i <= n; i++) {
		if(!used[i]) {
			dfs1(i);
		}
	}
	memset(used, false, sizeof(used));
	int cnt = 0;
	while(!st.empty()) {
		int u = st.top(); st.pop();
		if(!used[u]) {
			dfs2(u);
			cnt++;
		}
	}
	if(cnt == 1) cout << "YES\n";
	else cout << "NO\n";
}
int main() {
	int t; cin >> t;
	while(t--) {
		init();
		strongly_connected();
	}
}
