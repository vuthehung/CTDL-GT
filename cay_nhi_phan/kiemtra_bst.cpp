#include<bits/stdc++.h>
using namespace std;
bool check(int a[], vector<int> v, int n) {
	for(int i = 0; i < n; i++) {
		if(a[i] != v[i]) return false;
	}
	return true;
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int a[n];
		set<int> s;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			s.insert(a[i]);
		}
		vector<int> v;
		for(int x : s) v.push_back(x);
		if(check(a, v, n)) cout << 1 << endl;
		else cout << 0 << endl;
	}
}
