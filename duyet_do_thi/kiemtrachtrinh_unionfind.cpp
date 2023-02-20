#include<bits/stdc++.h>
using namespace std;

int n, m;
int parent[1001], size[1001];

int find(int x) {
	if(x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
bool Union(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return false;
	if(size[x] < size[y]) swap(x, y);
	parent[y] = x;
	size[x] += size[y];
	return true; 
}
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
		size[i] = 1;
	}
	bool ok = false;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		if(!Union(x, y)) ok = true;
	}
	if(ok) {
		cout << "YES\n";
	}else {
		cout << "NO\n";
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
