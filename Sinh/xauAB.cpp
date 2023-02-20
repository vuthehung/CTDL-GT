#include<bits/stdc++.h>
using namespace std;
int n, ok, a[11];
void ktao() {
    cin >> n;
    for(int i = 1; i <= n; i++) a[i] = 0;
}
void sinh() {
    int i = n;
    while(i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if(i == 0) ok = 0;
    else a[i] = 1;
}
int main() {
    int t; cin >> t;
    while(t--) {
        ktao();
        ok = 1;
        while(ok) {
            for(int i = 1; i <= n; i++) {
                if(a[i] == 0) {
                    cout << "A";
                }else if(a[i] == 1) cout << "B";
            }
            cout << " ";
            sinh();
        }
        cout << endl;
    }
}