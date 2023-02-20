#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1001][1001];
int d[1001][1001];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void inp() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
			d[i][j] = 1e9;
		}
	}
}
void djisktra() {
	d[1][1] = a[1][1];
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > Q;
	Q.push(make_pair(a[1][1], make_pair(1, 1)));
	while(!Q.empty()) {
		pair<int, pair<int, int> > top = Q.top(); Q.pop();
		int len = top.first;
		pair<int, int> pos = top.second;
		if(len > d[pos.first][pos.second]) continue;
		for(int k = 0; k < 4; k++) {
			int i1 = pos.first + dx[k];
			int j1 = pos.second + dy[k];
			if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m) {
				if(d[i1][j1] > d[pos.first][pos.second] + a[i1][j1]) {
					d[i1][j1] = d[pos.first][pos.second] + a[i1][j1];
					Q.push(make_pair(d[i1][j1], make_pair(i1, j1)));
				}
			}
		}
	}
	cout << d[n][m] << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		djisktra();
	}
}
