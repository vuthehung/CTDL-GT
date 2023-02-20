#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
int degree[1001]; // luu ban bac vao
int color[1001];//su dung de kiem tra dinh da duyet xong hay chua. Co 3 mau
				//trang(w) = 0: dinh chua dc duyet
				//xam(gray) = 1: dinh dang dc duyet
				//den(b) = 2: dinh da dc duyet xong(ko con dinh ke)

void init() {
	memset(degree, 0, sizeof(degree));
	for(int i = 1; i <= n; i++) adj[i].clear();
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		degree[y]++;
	}
	//memset(color, 0, sizeof(color));
}
bool chutrinh_dfs(int u) {
	color[u] = 1;
	for(int v : adj[u]) {
		if(color[v] == 0) {
			if(chutrinh_dfs(v)) return true;
		}else if(color[v] == 1) return true;
	}
	color[u] = 2;
	return false;
}
bool kahn() { // thuat toan xoa dan dinh
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		if(degree[i] == 0) q.push(i);
	}
	int cnt = 0; // dem xem thuat toan Kahn duyet dc bao nhieu dinh theo thu tu sap xep topo
	while(!q.empty()) {
		int v = q.front(); q.pop();
		cnt++;
		for(int x : adj[v]) {
			degree[x]--;
			if(degree[x] == 0) q.push(x);
		}
	}
	if(cnt == n) return false;
	return true;
}
int main() {
	int t; cin >> t;
	while(t--) {
		init();
//		for(int i = 1; i <= n; i++) {
//			if(color[i] == 0) {
//				if(chutrinh_dfs(i)) {
//					cout << "YES\n";
//					return 0;
//				}
//			}
//		}
//		cout << "NO\n";
		if(kahn()) {
			cout << "YES\n";
		}else {
			cout << "NO\n";
		}
	}
	return 0;
}
