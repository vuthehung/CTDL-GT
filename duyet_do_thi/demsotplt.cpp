#include<bits/stdc++.h>
using namespace std;

int n, m;
int tplt;
vector<int> adj[1001];
vector<vector<int> > v;
vector<int> x;
bool used[1001];

void init() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) adj[i].clear();
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	tplt = 0;
	memset(used, false, sizeof(used));
}
void dfs(int u) {
	used[u] = true;
	x.push_back(u);
	for(int x : adj[u]) {
		if(!used[x]) {
			dfs(x);
		}
	}
}
bool cmp(vector<int> a, vector<int> b) {
	return a.size() > b.size();
}
int main() {
	int t; cin >> t;
	while(t--) {
		init();
		for(int u = 1; u <= n; u++) {
			if(!used[u]) {
				tplt++;
				dfs(u);
				v.push_back(x);
				x.clear();
				cout << endl;
			}
		}
		sort(v.begin(), v.end(), cmp);
		cout << v[0].size() + v[1].size();
		
	}
}
