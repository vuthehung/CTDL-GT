#include<bits/stdc++.h>
using namespace std;

// sinh xau nhi phan thuan nghich
int a[1000], n, ok;
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
bool thuannghich(int a[], int n) {
    for(int i = 1; i <= n / 2; i++) {
        if(a[i] != a[n - i + 1]) return false;
    }
    return true;
}
int main() {
    ktao();
    ok = 1;
    vector<int> v;
    while(ok) {
        if(thuannghich(a, n)) {
            for(int i = 1; i <= n; i++) {
               v.push_back(a[i]);
            }
        }
        sinh();
    }
    int cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
        cnt++;
        if(cnt == n) {
            cout << endl;
            cnt = 0;
        }
    }
}