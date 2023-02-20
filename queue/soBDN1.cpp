#include<bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--) {
    	string s; cin >> s;
    	int cnt = 0;
		queue<string> q;
    	q.push("1");
    	while(1) {
    		string top = q.front(); q.pop();
    		if(top.size() > s.size() || (top.size() == s.size() && top > s)){
    			break;
			}
			cnt++;
			q.push(top + "0");
			q.push(top + "1");
		}
		cout << cnt << endl;
    }
}
