#include<bits/stdc++.h>
using namespace std;

int n, k, ok;
int a[11], b[11];
bool used[11];
void init() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a, a + n + 1);
    memset(used, false, sizeof(used));
    ok = 0;
}
void b_t(int i, int s, int sum) {
    if(sum == k) {
        cout << "[";
        for(int j = 1; j < s; j++) {
            cout << b[j];
            if(j != s - 1) cout << " ";
        }
        cout << "] ";
        ok = 1;
        return;
    }
    for(int j = i; j <= n; j++) {
        if(!used[j] && sum + a[j] <= k) {
            used[j] = true;
            b[s] = a[j];
            b_t(j, s + 1, sum + a[j]);
            used[j] = false;
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        init();
        b_t(1, 1, 0);
        if(ok) cout << endl;
        else  cout << "-1\n";
    }
}