#include<bits/stdc++.h>
using namespace std;

int cot[100], xuoi[100], nguoc[100], a[10][10], n, ans, x[100];

void inp() {
	n = 8;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	ans = 0;
	memset(cot, 1, sizeof(cot));
	memset(xuoi, 1, sizeof(xuoi));
	memset(nguoc, 1, sizeof(nguoc));
}
void Try(int i) {
	for(int j = 1; j <= 8; j++) {
		if(cot[j] && xuoi[i - j + n] && nguoc[i + j - 1]) {
			x[i] = j;
			cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
			if(i == 8) {
				int sum = 0;
				for(int k = 1; k <= 8; k++) {
					sum += a[k][x[k]];
				}
				ans = max(ans, sum);
			}else Try(i + 1);
			cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
		}
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		Try(1);
		cout << ans << endl;
	}
}
