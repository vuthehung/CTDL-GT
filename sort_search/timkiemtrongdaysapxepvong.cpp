#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		long n, k, h, j=0;
		cin >> n >> k;
		for(int i=1; i<=n; i++){
			cin >> h;
			if(h==k)	j=i;
		}
		cout << j <<endl;
	}
}

