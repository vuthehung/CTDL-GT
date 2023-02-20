#include<bits/stdc++.h>
using namespace std;

int n, m, s;
vector<int> adj[1001];
bool used[1001];

void init() {
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++) {
		int x, y; 
		cin >> x >> y;
		adj[x].push_back(y);
	}
	memset(used, false, sizeof(used));
}
void bfs(int u) {
	queue<int> q;
	q.push(u);
	used[u] = true;
	while(!q.empty()) {
		int v = q.front(); q.pop();
		cout << v << " ";
		for(int x : adj[v]) {
			if(!used[x]) {
				used[x] = true;
				q.push(x);
			}
		}
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		init();
		bfs(s);
		cout << endl;
		for(int i = 1; i <= n; i++) adj[i].clear();
	}
}
