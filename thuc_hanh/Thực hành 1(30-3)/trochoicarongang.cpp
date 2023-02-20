#include<bits/stdc++.h>
using namespace std;
int n, a[16], ok;
char c;
void init() {
    cin >> n >> c;
    for(int i = 1; i <= n; i++) a[i] = 0;
    ok = 1;
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
void in() {
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) cout << 'O';
        else cout << 'X';
    }
    cout << endl;
}
bool checkO() {
    for(int i = 1; i <= n - 1; i++) {
        if(a[i] == 0 && a[i + 1] == 1) return false;
    }
    for(int i = 1; i <= n - 1; i++) {
        if(a[i] == 1 && a[i + 1] == 1) return false;
    }
    for(int i = 1; i <= n - 2; i++) {
        if(a[i] == 1 && a[i + 1] == 1 && a[i + 2] == 1) return false;
    }
    for(int i = 1; i <= n - 3; i++) {
        if(a[i] == 1 && a[i + 1] == 1 && a[i + 2] == 1 && a[i + 1] == 1) return false;
    }
    return true;
}
bool checkX() {
    for(int i = 1; i <= n - 1; i++) {
        if(a[i] == 1 && a[i + 1] == 0) return false;
    }
    for(int i = 1; i <= n - 1; i++) {
        if(a[i] == 0 && a[i + 1] == 0) return false;
    }
    for(int i = 1; i <= n - 2; i++) {
        if(a[i] == 0 && a[i + 1] == 0 && a[i + 2] == 0) return false;
    }
    for(int i = 1; i <= n - 3; i++) {
        if(a[i] == 0 && a[i + 1] == 0 && a[i + 2] == 0 && a[i + 1] == 0) return false;
    }
    return true;
}
int main() {
    int t; cin >> t;
    while(t--) {
        init();
        while(ok) {
            if(c == 'O') {
                if(checkO()) {
                    in();
                }
            }else if(c == 'X') {
                if(checkX()){
                    in();
                }
            }
            sinh();
        }
    }
}