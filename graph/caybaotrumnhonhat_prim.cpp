#include<bits/stdc++.h>
using namespace std;

struct canh{
	int x, y, w;
};
int n, m;
vector<pair<int, int> > adj[1001];
bool used[1001];
int parent[1001], d[1001];

void inp() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	memset(used, false, sizeof(used));
	for(int i = 1; i <= n; i++) d[i] = INT_MAX;
}
void prim(int u) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
	
	vector<canh> MST;
	int cost_MST = 0;
	Q.push({0, u});
	while(!Q.empty()) {
		pair<int, int> top = Q.top(); Q.pop();
		int dinh = top.second, trongso = top.first;
		if(used[dinh]) continue;
		
		cost_MST += trongso;
		used[dinh] = true;
		if(u != dinh) {
			MST.push_back({dinh, parent[dinh], trongso});
		}
		for(auto it : adj[dinh]) {
			int y = it.first, w = it.second;
			if(!used[y] && w < d[y]) {
				Q.push({w, y});
				parent[y] = dinh;
				d[y] = w;
			}
		}
	}
	cout << cost_MST << endl;
	for(auto it : MST) {
		cout << it.x << " " << it.y << " " << it.w << endl;
	}

}
int main() {
	inp();
	prim(6);
}
