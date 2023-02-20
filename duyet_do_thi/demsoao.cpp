#include<bits/stdc++.h>
using namespace std;

int n, m;
char a[101][101];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int i, int j) {
	a[i][j] = '.';
	for(int k = 0; k < 8; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'W') {
			dfs(i1, j1);
		}
	}
}
void tplt() {
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j] == 'W') {
				cnt++;
				dfs(i, j);
			}
		}
	}
	cout << cnt;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	tplt();
}
