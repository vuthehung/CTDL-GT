#include<bits/stdc++.h>
using namespace std;
int n, ok, a[9];
void ktao() {
    ok = 1;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
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
    ktao();
    while(ok) {
        for(int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
        sinh();
    }
}