#include<bits/stdc++.h>
using namespace std;
int n, a[21];
string s;
vector<int> x;
vector<string> v;
vector<vector<int> > y;

void Try(int pos) {
	for(int i = pos + 1; i <= n; i++) {
		if(a[i] > a[pos]) {
			x.push_back(a[i]);
			if(x.size() > 1) {
				y.push_back(x);
			}
			Try(i);
			x.erase(x.end() - 1, x.end());
		}
	}
}
int main() {
	cin >> n;
	a[0] = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	Try(0);
	for(int i = 0; i < y.size(); i++) {
		s = "";
		for(int j = 0; j < y[i].size(); j++) {
			s += to_string(y[i][j]);
			s += " ";
		}
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
