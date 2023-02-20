#include<bits/stdc++.h>
using namespace std;

int n, k, ans;
int x[10];
bool used[10];
vector<string> v;
int sub_max_min() {
	int max_ = INT_MIN, min_ = INT_MAX;
	for(int i = 0; i < v.size(); i++) {
		int t = 0;
		for(int j = 0; j < k; j++) {
			t = t * 10 + (v[i][x[j]] - '0');
		}
		max_ = max(max_, t);
		min_ = min(min_, t);
	}
	return max_ - min_;
}
void Try(int i) {
	for(int j = 0; j < k; j++) {
		if(!used[j]) {
			x[i] = j;
			used[j] = true;
			if(i == k - 1) {
				ans = min(ans, sub_max_min());
			}else Try(i + 1);
			used[j] = false;
		}
	}
}
void solve() {
	cin >> n >> k;
	v.clear();
	string s;
	ans = INT_MAX;
	for(int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	Try(0);
	cout << ans;
}
int main() {
	solve();
}
