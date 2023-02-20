#include<bits/stdc++.h>
using namespace std;

int n, cnt;
int a[1001][1001];
string s = "";
vector<string> v;
void inp() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	cnt = 0;
}
void b_t(int i, int j) {
	if(i == n && j == n) {
		v.push_back(s);
		s = "";
		return;
	}
	if(i + 1 <= n) {
		s += a[i + 1][j];
		b_t(i + 1, j);
	}
	if(j + 1 <= n) {
		s += a[i][j + 1];
		b_t(i, j + 1);
	}
}
int main() {
	inp();
	b_t(1, 1);
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[i].length(); j++) {
			cout << v[i][j];
		}
		cout << endl;
	}
}
