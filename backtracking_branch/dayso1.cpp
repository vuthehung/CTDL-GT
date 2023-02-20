#include<bits/stdc++.h>
using namespace std;
int n, a[11];
void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void back_track(int index) {
    if(index == 0) return;
    cout << "[";
    for(int i = 1; i <= index; i++) {
        cout << a[i];
        if(i == index) cout << "]";
        else cout << " ";
    }
    cout << endl;
    for(int i = 1; i < index; i++) {
        a[i] += a[i + 1];
    }
    back_track(index - 1);
}
int main() {
    int t; cin >> t;
    while(t--) {
        init();
        back_track(n);
    }
}