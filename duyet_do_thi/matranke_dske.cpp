#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> adj[1001];
	int a[n + 1][n + 1];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if(a[i][j] == 1 && i > j) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < adj[i].size(); j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}
