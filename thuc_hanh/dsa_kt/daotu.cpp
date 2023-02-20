#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	cin.ignore();
	while(t--) {
		stack<char> st;
		vector<string> res;
		string s; 
		getline(cin, s);
		stringstream ss(s);
		string tmp;
		while(ss >> tmp) {
			res.push_back(tmp);
		}
		vector<string> ans;
		for(int i = 0; i < res.size(); i++) {
			reverse(res[i].begin(), res[i].end());
		}
		for(int i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
}
