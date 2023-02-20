#include<bits/stdc++.h>
using namespace std;
void solve(string s) {
    stack<int> st;
    for(int i = s.length() - 1; i >= 0; i--) {
        if(isdigit(s[i])) {
            st.push(stoi(string(1, s[i])));
        }else {
            int opr1 = st.top(); st.pop();
            int opr2 = st.top(); st.pop();
            int res;
            switch(s[i]) {
				case '+':
					res = opr1 + opr2;
					break;
				case '-':
					res = opr1 - opr2;
					break;
				case '*':
					res = opr1 * opr2;
					break;
				case '/':
					res = opr1 / opr2;
					break;
			}
            st.push(res);
        }
    }
    cout << st.top() << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        solve(s);
    }
}