#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n, m, x;
		cin >> n >> m >> x;
		int a[n], b[m];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < m; i++) cin >> b[i];
		vector<int> res;
		int i = 0, j = 0;
		while(i < n && j < m) {
			if(a[i] <= b[j]) {
				res.push_back(a[i]);
				i++;
			}else {
				res.push_back(b[j]);
				j++;
			}
		}
		while(i < n){
			res.push_back(a[i]);
			i++;
		}
		while(j < m){
			res.push_back(b[j]); 
			j++;
		}
		cout << res[x - 1] << endl;
	}
}
