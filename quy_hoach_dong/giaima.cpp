#include<bits/stdc++.h>
using namespace std;
#define int long long
main() {
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		int n = s.length();
		if(s[0] == '0') cout << "0\n";
		else {
			int f[100] = {0};
			f[0] = f[1] = 1;
			for(int i = 2; i <= 100; i++) {
				if(s[i - 1] > '0') f[i] = f[i - 1];
				if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) {
					f[i] += f[i - 2];
				}
			}
			cout << f[n];
		}
		cout << endl;
	}	
}
