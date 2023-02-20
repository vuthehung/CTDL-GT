#include<bits/stdc++.h>
using namespace std;
int n, a[100], x;
vector <vector<int> > ans;

void b_t(int i, int sum, vector<int> v) {
	if(sum == x) {
		ans.push_back(v);
		return;
	}
	for(int j = i; j <= n; j++) {
		if(sum + a[j] <= x) {
			v.push_back(a[j]);
			b_t(j, sum + a[j], v);
			v.pop_back();
		}
	}
}
void solve() {
	cin >> n >> x;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ans.clear();
	vector<int> v;
	v.clear();
	b_t(1, 0, v);
	if(ans.size() == 0) cout << -1 << endl;
	else {
		cout << ans.size() << " ";
		sort(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); i++) {
			cout << "{";
			for(int j = 0; j < ans[i].size() - 1; j++) {
				cout << ans[i][j] << " ";
			}
			cout << ans[i][ans[i].size() - 1] << "} ";
		}
		cout << endl;
	}
}
main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}

