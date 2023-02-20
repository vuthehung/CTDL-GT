#include<bits/stdc++.h>
using namespace std;

int A, B, C, si, sj, sk, ei, ej, ek;
char a[31][31][31];
int cnt[31][31][31];
int dx[6] = {-1, 0, 0, 1, 0, 0}; //for j
int dy[6] = {0, -1, 1, 0, 0, 0}; //for k
int dz[6] = {0, 0, 0, 0, 1, -1}; //for i

void bfs(int i, int j, int k) {
	queue<pair<pair<int, int>, int> > q;
	a[i][j][k] = '#';
	cnt[i][j][k] = 0;
	q.push(make_pair(make_pair(i, j), k));
	while(!q.empty()) {
		pair<pair<int, int>, int> t = q.front(); q.pop();
		int i = t.first.first, j = t.first.second, k = t.second;
		for(int l = 0; l < 6; l++) {
			int i1 = i + dz[l];
			int j1 = j + dx[l];
			int k1 = k + dy[l];
			if(i1 >= 1 && i1 <= A && j1 >= 1 && j1 <= B && k1 >= 1 && k1 <= C && a[i1][j1][k1] != '#') {
				a[i1][j1][k1] = '#';
				q.push(make_pair(make_pair(i1, j1), k1));
				cnt[i1][j1][k1] = cnt[i][j][k] + 1;
				if(i1 == ei && j1 == ej && k1 == ek) return;
			}
		}
	}
}
void inp() {
	cin >> A >> B >> C;
	for(int i = 1; i <= A; i++) {
		for(int j = 1; j <= B; j++) {
			for(int k = 1; k <= C; k++) {
				cin >> a[i][j][k];
				if(a[i][j][k] == 'S') {
					si = i; sj = j; sk = k;
				}else if(a[i][j][k] == 'E') {
					ei = i; ej = j; ek = k;
				}
			}
		}
	}
}

int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		bfs(si,sj, sk);
		if(a[ei][ej][ek] == 'E') {
			cout << "-1\n";
		}else cout << cnt[ei][ej][ek] << endl;
		memset(cnt, 0, sizeof(cnt));
	}
}
