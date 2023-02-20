#include<bits/stdc++.h>
using namespace std;
int n, ok, a[1001];
void ktao() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void sinh() {
    int i = n - 1;
    while(i >= 1 && a[i] > a[i + 1]) i--;
    if(i == 0) ok = 0;
    else {
        int j = n;
        while(a[i] > a[j]) j--;
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        ktao();
        ok = 1;
        if(ok) {
            sinh();
            for(int i = 1; i <= n; i++) cout << a[i] << " ";
            
        }
        cout << endl;
    }
}