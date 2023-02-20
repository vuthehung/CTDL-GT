#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int d[100001];
bool used[100001];
int n;

void init() {
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(used, false, sizeof(used));
	memset(d, 0, sizeof(d));
}
void bfs(int u) {
	d[u] = 0;
	used[u] = true;
	queue<int> q;
	q.push(u);
	while(!q.empty()) {
		int t = q.front(); q.pop();
		for(int x : adj[t]) {
			if(!used[x]) {
				used[x] = true;
				d[x] = d[t] + 1;
				q.push(x);
			}
		}
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		init();
		bfs(1);
		cout << *max_element(d + 1, d + n + 1) << endl;
		for(int i = 1; i <= n; i++) adj[i].clear();
	}
}
