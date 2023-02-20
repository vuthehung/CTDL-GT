#include<bits/stdc++.h>
using namespace std;
int n, m, a[11];
bool used[11];
void init() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) a[i] = i;
    memset(used, false, sizeof(used));
}
bool check() {
	return a[n] == m;
}
void in() {
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
}
void b_t(int i) {
    for(int j = 1; j <= n; j++) {
        if(!used[j]) {
            a[i] = j;
            used[j] = true;
            if(i == n) {
                if(check()) {
                	in();
                	cout << endl;
				}
            }else b_t(i + 1);
            used[j] = false;
        } 
    }
}
int main() {
    int t = 1;
    while(t--) {
        init();
        b_t(1);
        cout << endl;
    }
}
