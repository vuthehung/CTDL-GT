#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok, cnt;
void ktao() {
    cnt = 1; a[1] = n;
}
void sinh() {
    int i = cnt;
    int d = 0;
    while(i >= 1 && a[i] == 1) i--;
    if(i == 0) ok = 0;
    else {
        a[i]--;
        d = cnt - i + 1;
        int q = d / a[i]; int r = d % a[i];
        cnt = i;
        if(q) {
            for(int j = 0; j < q; j++) a[j + i + 1] = a[i];
            cnt += q;
        }
        if(r) {
            a[cnt + 1] = r; cnt++;
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        ktao();
        ok = 1;
        while(ok) {
            cout << "(";
            for(int i = 1; i <= cnt; i++) {
                cout << a[i];
                if(i == cnt) cout << ") ";
                else cout << " ";
            }
            sinh();
        }
        
        cout << endl;
    }
}