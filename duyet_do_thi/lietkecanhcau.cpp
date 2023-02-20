#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
vector<pair<int, int> > edge;
bool used[1001];

void init() {
	for(int i = 1; i <= n; i++) {
		adj[i].clear();
	}
	edge.clear();
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		edge.push_back({x, y});
	}
}
void dfs(int u) {
	used[u] = true;
	for(int v : adj[u]) {
		if(!used[v]) {
			used[v] = true;
			dfs(v);
		}
	}
}
void dfs2(int u, int s, int t) {
	used[u] = true;
	for(int v : adj[u]) {
		if((u == s && v == t) || (u == t && v == s)) continue; //loai bo canh(s,t)
		if(!used[v]) {
			dfs2(v, s, t);
		}
	}
}
void canhcau() {
	//thuc hien dem so tplt cua do thi
	int tplt = 0;
	memset(used, false, sizeof(used));
	for(int i = 1; i <= n; i++) {
		if(!used[i]) {
			dfs(i);
			tplt++;
		}
	}
	//kiem tra canh cau
	for(auto it : edge) {
		int x = it.first, y = it.second;
		memset(used, false, sizeof(used));
		int dem = 0;
		for(int j = 1; j <= n; j++) {
			if(!used[j]) {
				dem++;
				dfs2(j, x, y);
			}
		}
		if(dem > tplt) cout << x << " " << y << " "; 
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		init();
		canhcau();
		cout << endl;
	}
}
