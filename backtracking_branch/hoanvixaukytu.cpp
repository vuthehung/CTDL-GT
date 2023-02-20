#include<bits/stdc++.h>
using namespace std;
string s;
int a[100], n;
bool used[100];
void init() {
    cin >> s;
    n = s.length();
    memset(used, false, sizeof(used));
}
void back_track(int i) { // quay lui sinh hoan vi
    for(int j = 0; j < n; j++) {
        if(!used[j]) {
            a[i] = j;
            used[j] = true;
            if(i == n - 1) {
                for(int i = 0; i < n; i++) {
                    cout << s[a[i]];
                }
                cout << " ";
            }else back_track(i + 1);
            used[j] = false;
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        init();
        back_track(0);
        cout << endl;
    }
}