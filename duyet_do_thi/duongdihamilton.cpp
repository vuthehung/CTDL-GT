#include<bits/stdc++.h>
using namespace std;

int n, m, ok;
vector<int> adj[1001];
bool used[1001];

void Try(int u, int cnt) {
	if(cnt == n) {
		ok = 1; return;
	}
	for(int x : adj[u]) {
		if(!used[x]) {
			used[x] = true;
			Try(x, cnt + 1);
			used[x] = false;
		}
	}
}
void inp() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ok = 0;
	memset(used, false, sizeof(used));
	for(int i = 1; i <= n; i++) {
		used[i] = true;
		Try(i, 1);
		used[i] = false;
		if(ok) break;
	}
	cout << ok << endl;
	
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		for(int i = 1; i <= n; i++) adj[i].clear();
	}
}
