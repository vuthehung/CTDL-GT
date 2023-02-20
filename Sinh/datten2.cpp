#include<bits/stdc++.h>
using namespace std;
int n, k, ok, a[16];
void ktao() {
    ok = 1; 
    cin >> n >> k;
    for(int i = 1; i <= k; i++) a[i] = i;
}
void sinh() {
    int i = k;
    while(i >= 1 && a[i] == n - k + i) i--;
    if(i == 0) ok = 0;
    else {
        a[i]++;
        for(int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
    }
}
void in() {
    for(int i = 1; i <= k; i++) {
        cout << (char)(a[i] + 64);
    }
    cout << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        ktao();
        while(ok) {
            in();
            sinh();
        }
    }
}