#include<bits/stdc++.h>
using namespace std;

int n, m, s;
int a[1001][1001];
vector<pair<int, int> > adj[1001];
vector<int> d;

void init() {
////	cin >> n >> m;
//	cin >> n >> s;
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++) {
//			cin >> a[i][j];
//			if(a[i][j] != 0) {
//				adj[i].push_back({j, a[i][j]});
//			}
//		}
//	}
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
	}
}
void dijkstra(int s) {
	d.assign(n + 1, 1e9);
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push({0, s});
	while(!q.empty()) {
		//lay phan tu o dinh hang doi
		pair<int, int> top = q.top(); q.pop();
		int u = top.second;
		int len = top.first;
		if(len > d[u]) continue;
		for(pair<int, int> it : adj[u]) {
			int v = it.first, w = it.second;
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({d[v], v});
			}
		}
	}
	//output: trong so duong di ngan nhat tu dinh s den dinh con lai
	for(int i = 1; i <= n; i++) cout << d[i] << " ";
	cout << endl;
}
int main() {
	init();
	dijkstra(s);
}
	
