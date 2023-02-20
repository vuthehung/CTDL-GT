#include<bits/stdc++.h>
using namespace std;

int n, m, M, color[101];
vector<int> adj[1001];
bool ok;

void Try(int i) {
	if(ok) return;
	for(int j = 1; j <= M; j++) {
		color[i] = j;
		if(i == n - 1) {
			bool res = true;
			for(int k = 1; k <= n; k++) {
				for(int x : adj[k]) {
					if(color[x - 1] == color[k - 1]) {
						res = false;
						break;
					}
				}
				if(!res) break;
			}
			if(res) ok = res;
		}else Try(i + 1);
	}
}
void inp() {
	cin >> n >> m >> M;
	ok = false;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	Try(0);
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		for(int i = 1; i <= n; i++) adj[i].clear();
	}
}
