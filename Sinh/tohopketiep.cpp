#include<bits/stdc++.h>
using namespace std;

int n, k, ok, a[1001];
void ktao() {
    cin >> n >> k;
    for(int i = 1; i <= k; i++) cin >> a[i];
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
int main() {
    int t; cin >> t;
    while(t--) {
        ktao();
        ok = 1;
        if(ok) {
            sinh();
            for(int i = 1; i <= k; i++) cout << a[i] << " ";
        }
        cout << endl;
    }
}