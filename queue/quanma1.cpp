#include<bits/stdc++.h>
using namespace std;

string res = "abcdefgh";
string s1, s2;
int si, sj, ei, ej;
int a[9][9];
int cnt[9][9];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void bfs(int i, int j) {
	queue<pair<int, int> > q;
	a[i][j] = 0;
	cnt[i][j] = 0;
	q.push({i, j});
	while(!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		int i = t.first, j = t.second;
		for(int k = 0; k < 8; k++) {
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if(i1 >= 1 && i1 <= 8 && j1 >= 1 && j1 <= 8 && a[i1][j1] != -1) {
				q.push({i1, j1});
				cnt[i1][j1] = cnt[i][j] + 1;
				if(i1 == ei && j1 == ej) return;
				a[i1][j1] = -1;
			}
		}
	}
}
void inp() {
	cin >> s1 >> s2;
	for(int i = 0; i < res.length(); i++) {
		if(s1[0] == res[i]) si = i + 1;
		if(s2[0] == res[i]) ei = i + 1;
	}
	sj = s1[1] - '0';
	ej = s2[1] - '0';
	memset(a, 0, sizeof(a));
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		bfs(si, sj);
		if(si == ei && sj == ej) cout << 0 << endl;
		else cout << cnt[ei][ej] << endl;
		memset(cnt, 0, sizeof(a));
	}
}
