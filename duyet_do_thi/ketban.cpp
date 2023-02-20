#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> parent, sz;

int find(int x) {
	if(x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) {
		if(sz[x] < sz[y]) {
			swap(x, y);
		}
		sz[x] += sz[y];
		parent[y] = x;
	}
}
void inp() {
	cin >> n >> m;
	parent.resize(n + 1);
	sz.assign(n + 1, 1);
	for(int i = 1; i <= n; i++) parent[i] = i;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		Union(x, y);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, sz[i]);
	}
	cout << ans << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		parent.clear();
		sz.clear();
	}
}
