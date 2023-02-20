#include<bits/stdc++.h>
using namespace std;

int n, m;
char a[1001][1001];
bool visited[1001][1001];
int dx[4] = {-1, 0, 0, 1}; //gia tri ma i dich chuyen
int dy[4] = {0, -1, 1, 0};// gia tri ma j dich chuyen

void dfs(int i, int j) {
	visited[i][j] = true;
	for(int k = 0; k < 4; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x' && !visited[i1][j1]) {
			dfs(i1, j1);
		}
	}
}
void bfs(int i, int j) {
	queue<pair<int, int> > q;
	q.push({i, j});
	a[i][j] = 'o';
	while(!q.empty()) {
		pair<int, int> top = q.front(); q.pop();
		for(int k = 0; k < 4; k++) {
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x') {
				bfs(i1, j1);
				a[i1][j1] = 'o';
			}
		}
	}
}
void tplt() {
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
//			if(a[i][j] == 'x' && !visited[i][j]) {
//				cnt++;
//				dfs(i, j);
//			}	
			if(a[i][j] == 'x') {
				cnt++;
				bfs(i, j);
			}
		}
	}
	cout << cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	tplt();
}
