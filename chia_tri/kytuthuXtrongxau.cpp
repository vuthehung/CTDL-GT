#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int l = 1;
		while(k % 2 == 0) {
			k /= 2;
			l++;
		}
		cout << (char)(l + 64) << endl;
	}
}
