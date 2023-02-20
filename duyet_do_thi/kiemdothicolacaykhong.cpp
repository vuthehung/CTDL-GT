#include<bits/stdc++.h>
using namespace std;

int n, parent[1001], size[1001];

int find(int x) {
	if(x = parent[x]) return x;
	return parent[x] = find(parent[x]);
}
bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return false;
	if(size[a] < size[b]) {
		swap(a, b);	
	}
	size[a] += size[b];
	parent[b] = a;
	return true;
}
void inp() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
		size[i] = 1;
	}
	bool ok = true;
	for(int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		ok &= Union(x, y);
	}
	cout << (ok ? "YES\n" : "NO\n");
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
	}
}
