#include<bits/stdc++.h>
using namespace std;

int n;
int a[20];
vector<vector<int> > ans;

int ngto(int a) {
	if(a == 1 || a == 0) return 0;
	else {
		for(int i = 2; i <= sqrt(a); i++) {
			if(a % i == 0) {
				return 0;
			}
		}
	}
	return 1;
}
void b_t(int i, int sum, vector<int> v) {
	if(ngto(sum)) {
		ans.push_back(v);
	}
	for(int j = i + 1; j <= n; j++) {
		v.push_back(a[j]);
		b_t(j, sum + a[j], v);
		v.pop_back();
	}
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
	ans.clear();
	vector<int> v;
	v.clear();
	b_t(0, 0, v);
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
