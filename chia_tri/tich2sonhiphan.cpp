#include<bits/stdc++.h>
using namespace std;

long long a[35];
string s1, s2;

void hai_mu_X() {
	a[0] = 1;
	for(int i = 1; i <= 30; i++) {
		a[i] = a[i - 1] * 2;
	}
}
long long bina_dec(string s) {
	long long sum = 0;
	for(int i = 0; i < s.length(); i++) {
		sum += (s[i] - '0') * a[s.length() - i - 1];
	}
	return sum;
}
void solve() {
	cin >> s1 >> s2;
	cout << bina_dec(s1) * bina_dec(s2) << endl;
}
int main() {
	hai_mu_X();
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
