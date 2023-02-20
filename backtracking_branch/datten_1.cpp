#include<bits/stdc++.h>
using namespace std;
int n, k, idx;
vector<string> a;
int b[15];
void Try(int i) {
    for(int j = b[i - 1] + 1; j <= idx - k + i; j++) {
        b[i] = j;
        if(i == k) {
            for(int l = 1; l <= k; l++) {
                cout << a[b[l] - 1] << " ";
            }
            cout << endl;
        }else Try(i + 1);
    }
}
int main() {
	set<string> s;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		string x; cin >> x;
		s.insert(x);
	}
	for(auto it : s) {
        a.push_back(it);
    }
    idx = a.size();
    for(int i = 1; i <= k; i++) b[i] = i;
    Try(1);
}