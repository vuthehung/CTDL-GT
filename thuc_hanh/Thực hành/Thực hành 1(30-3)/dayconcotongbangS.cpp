#include<bits/stdc++.h>
using namespace std;
int n, ok;
long long s, a[31], x[31];
bool used[31];  
int ans;
void init() {
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    memset(used, false, sizeof(used));
    ok = 0;
    ans = 30;
}
void b_t(int i, int k, long long sum) {

    if(sum == s) {
        int cnt = 0;
        for(int j = 1; j < k; j++) cnt++;
        if(ans > cnt) ans = cnt;
        ok = 1;
        return;
    }
    for(int j = i; j <= n; j++) {
        if(!used[j] && sum + a[j] <= s) {
            used[j] = true;
            x[k] = a[j];
            b_t(j, k + 1, sum + a[j]);
            used[j] = false;
        }
    }
}
int main() {
    init();
    b_t(1, 1, 0);
    cout << ans;
}