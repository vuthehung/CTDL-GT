#include<bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];
vector<pair<int, int> > edge;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	cin.ignore();
	for(int i = 1; i <= n; i++) {
		string s, num;
		getline(cin, s);
		stringstream ss(s);
		while(ss >> num) {
			if(i < stoi(num)) {
				edge.push_back({i, stoi(num)});
			}
		}
	}
	for(auto it : edge) {
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}


