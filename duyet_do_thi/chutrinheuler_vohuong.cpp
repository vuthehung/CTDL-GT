#include<bits/stdc++.h>
using namespace std;

/* 
vo huong:
- chu trinh euler: neu tat ca cac dinh co bac chan
- duong di euler:  neu ton tai duy nhat 2 dinh le, duong di bat dau va ket thuc tai 2 dinh le do
*/

int main() {
	int t; cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int deg[1001] = {0};
		for(int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			deg[x]++; deg[y]++;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(deg[i] % 2 == 1) {
				cnt++;
			}
		}
		if(cnt == 2) cout << "1\n";
		else if(cnt == 0) cout << "2\n";
		else cout << "0\n";
		
	}
}
