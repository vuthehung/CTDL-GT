#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		string s; int k;
		cin >> k >> s;
		for(int i = 0; i < s.length(); i++) {
			int max = s[s.length() - 1];
			int idx_max = s.length() - 1;
			for(int j = s.length() - 1; j > i; j--) {
				if(s[j] > max) {
					max = s[j];
					idx_max = j;
				}
			}
			if(s[i] < max && k) {
				swap(s[i], s[idx_max]);
				k--;
			}
		}
		cout << s << endl;
	}
}
