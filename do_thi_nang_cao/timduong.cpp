#include<bits/stdc++.h>
using namespace std;

int n, m, si, sj, ei, ej, cnt;
char a[1001][1001];
int d[1001][1001];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
void bfs(int i, int j) {
	queue<pair<int, int> > q;
	q.push({i, j});
	a[i][j] = '.';
	d[i][j] = 0;
	while(!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		int i = t.first, j = t.second;
		for(int k = 0; k < 4; k++) {
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != '*') {
				d[i1][j1] = d[i][j] + 1;
				q.push({i1, j1});
				if(i1 == i - 1 || i1 == i + 1 || j1 == j - 1 || j1 == j + 1) cnt++;
				if(i1 == ei && j1 == ej) return;
				a[i1][j1] = '*';

			}
		}
	}
}
void inp() {
	cnt = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if(a[i][j] == 'S') {
				si = i; sj = j;
			}else if(a[i][j] == 'T') {
				ei = i; ej = j;
			}
		}
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		bfs(si, sj);
		cout << cnt << endl;
	}
}
