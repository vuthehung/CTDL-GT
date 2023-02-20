#include<bits/stdc++.h>
using namespace std;

//dinh u la dinh tru neu loai bo u va canh noi voi u lam tang tplt

int n, m;
vector<int> adj[1001];
bool used[1001];

void init() {
	for(int i = 1; i <= n; i++) adj[i].clear();
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
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
void dinhtru() {
	memset(used, false, sizeof(used));
	//dem so tplt
	int tplt = 0;
	for(int i = 1; i <= n; i++) {
		if(!used[i]) {
			dfs(i);
			tplt++;
		}
	}
	//dinh tru
	for(int i = 1; i <= n; i++) {
		memset(used, false, sizeof(used));
		//loai bo dinh i
		used[i] = true;
		int dem = 0; // kiem tra so tplt sau khi loai dinh i
		for(int j = 1; j <= n; j++) {
			if(!used[j]) {
				dem++;
				dfs(j);
			}
		}
		if(dem > tplt) cout << i << " ";
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		init();
		dinhtru();
		cout << endl;
	}
}
