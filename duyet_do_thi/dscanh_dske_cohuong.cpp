#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		vector<int> adj[10001];
		int v, e;
		cin >> v >> e;
		for(int i = 0; i < e; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for(int i = 1; i <= v; i++) {
			cout << i << ": ";
			for(int j = 0; j < adj[i].size(); j++) {
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}
	}
}
