#include<bits/stdc++.h>
using namespace std;

int a[10][10], kq[10][10];
string b = "abcdefgh";

struct pairs{
	int x, y;
};
int find(char c, string s) {
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == c) return i + 1;
	}
}
pairs gan(int x, int y) {
	pairs t;
	t.x = x;
	t.y = y;
	return t;
} 
pairs doi(string s) {
	pairs t;
	int k = find(s[0], b);
	t.x = k;
	t.y = (s[1] - '0');
	return t;
}
void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	memset(kq, -1, sizeof(kq));
	pairs t1 = doi(s1);
	pairs t2 = doi(s2);
	queue<pairs> q;
	pairs t;
	t.x = t1.x; t.y = t1.y;
	int m = t2.x, n = t2.y;
	q.push(t);
	kq[t1.x][t1.y] = 0;
	while(kq[m][n] == -1) {
		pairs t = q.front(); q.pop();
		int x = t.x, y = t.y;
		if(kq[x - 2][y - 1] && x - 2 >= 1 && y - 1 >= 1) {
			kq[x - 2][y - 1] = kq[x][y] + 1;
			pairs t = gan(x - 2, y - 1);
			q.push(t);
		}
		if(kq[x - 1][y - 2] && x - 1 >= 1 && y - 2 >= 1) {
			kq[x - 1][y - 2] = kq[x][y] + 1;
			pairs t = gan(x - 1, y - 2);
			q.push(t);	
		}
		if(kq[x + 2][y + 1] && x + 2 <= 8 && y + 1 <= 8) {
			kq[x + 2][y + 1] = kq[x][y] + 1;
			pairs t = gan(x + 2, y + 1);
			q.push(t);
		}
		if(kq[x + 1][y + 2] && x + 1 <= 8 && y + 2 <= 8) {
			kq[x + 1][y + 2] = kq[x][y] + 1;
			pairs t = gan(x + 1, y + 2);
			q.push(t);
		}
		if(kq[x - 2][y + 1] && x - 2 >= 1 && y + 1 <= 8) {
			kq[x - 2][y + 1] = kq[x][y] + 1;
			pairs t = gan(x - 2, y + 1);
			q.push(t);
		}
		if(kq[x + 2][y - 1] && x + 2 <= 8 && y - 1 >= 1) {
			kq[x + 2][y - 1] = kq[x][y] + 1;
			pairs t = gan(x + 2, y - 1);
			q.push(t);
		}
		if(kq[x - 1][y + 2] && x - 1 >= 1 && y + 2 <= 8) {
			kq[x - 1][y + 2] = kq[x][y] + 1;
			pairs t = gan(x - 1, y + 2);
			q.push(t);
		}
		if(kq[x + 1][y - 2] && x + 1 <= 8 && y - 2 >= 1) {
			kq[x + 1][y - 2] = kq[x][y] + 1;
			pairs t = gan(x + 1, y - 2);
			q.push(t);
		}
	}
	cout << kq[m][n] << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();	
	}
}
