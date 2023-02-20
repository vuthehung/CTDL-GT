#include<bits/stdc++.h>
using namespace std;

/* 
Do thi co huong:
-chu trinh euler: ban bac vao = ban bac ra
-duong di euler: ton tai duy nhat 2 dinh ma ban bac vao va ra chenh lech 1
=> dinh co ban bac ra = vao + 1: dinh bat dau, vao = ra + 1: dinh ket thuc 
*/


int main() {
	int t; cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int deg_in[1001] = {0};
		int deg_out[1001] = {0};
		for(int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			deg_in[x]++; deg_out[y]++;
		}
		int ok = 1;
		for(int i = 1; i <= n; i++) {
			if(deg_in[i] != deg_out[i]) {
				ok = 0;
			}
		}
//		if(ok == 1) cout << "1\n";
//		else cout << "0\n";
		cout << ok << endl;
	}
}
