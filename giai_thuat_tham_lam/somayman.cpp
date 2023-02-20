#include<bits/stdc++.h>
using namespace std;

//bieu thuc n = 4 * x + 7 * y
//der thoa man: so tim dc la nho nhat thi can nhieu so 7 nhat( y lon nhat co the).
void solve() {
	int n; cin >> n;
	for(int y = n / 7; y >= 0; y--) {
		if((n - 7 * y) % 4 == 0) {
			for(int i = 0; i < (n - 7 * y) / 4; i++) cout << "4";
			for(int i = 0; i < y; i++) cout << "7";
			cout << endl;
			return;
		}
	}
	cout << "-1\n";
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
