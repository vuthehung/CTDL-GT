#include<bits/stdc++.h>
using namespace std;

//Bellman ford: ap dung do thi co trong so am
//chu trinh am: tong trong so cua 1 chu trinh < 0

vector<pair<int, int> > adj[1001];
int n, m;
int s, a[1001][1001];

void init() {
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
	 	int x, y, w; cin >> x >> y >> w;
	 	adj[x].push_back({y, w});
	 }
}

void bellman_ford(int s) {
	vector<int> d(n + 1, 1e9);
	d[s] = 0;
	//Lap n - 2 buoc
	for(int i = 1; i <= n - 2; i++) {
		//xet tat ca cac cap canh cua do thi va cap nhat dan
		for(int u = 1; u <= n; u++) {
			//doi voi dinh u, xet tat ca dinh v ke voi u
			for(auto it : adj[u]) {
				int v = it.first, c = it.second;
				d[v] = min(d[v], d[u] + c);
			}
		}	
	}
	for(int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
}
int main() {
	init();
	bellman_ford(s);
}
