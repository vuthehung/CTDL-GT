#include<bits/stdc++.h>
using namespace std;

int n, p, s, m, x[100], ans;
bool used[100];
vector<int> prime;
vector<vector<int> > res;

bool ngto(int a) {
	for(int i = 2; i <= sqrt(a); i++) {
		if(a % i == 0) return false;
	}
	return a > 1;
}
void inp() {
	res.clear();
	prime.clear();
	cin >> n >> p >> s;
	for(int i = p + 1; i <= s; i++) {
		if(ngto(i)) prime.push_back(i);
	}
	memset(used, false, sizeof(used));
	m = prime.size();
	ans = 0;
}
void b_t(int sum, int pos, int cnt) {
	if(sum == s && cnt == n) {
		ans++;
		vector<int> tmp(x, x + cnt);
		res.push_back(tmp);
		return;
	}
	for(int j = pos; j < m; j++) {
		if(!used[j] && sum + prime[j] <= s) {
			used[j] = true;
			x[cnt] = prime[j];
			b_t(sum + prime[j], j, cnt + 1);
			used[j] = false;
		}
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();	
		b_t(0, 0, 0);
		cout << ans << endl;
		for(int i = 0; i < res.size(); i++) {
			for(int x : res[i]) {
				cout << x << " ";
			}
			cout << endl;
		}
	}
}
