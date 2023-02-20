// tổ hợp tiếp theo có bao nhiêu phần tử mới.

#include<bits/stdc++.h>
using namespace std;
int n, k, ok, a[41], b[41], c[41];
void ktao() {
    ok = 1;
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        cin >> a[i];
        c[i] = a[i];
    }
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
int check() {
    int cnt = 0;
    set<int> st;
    for(int i = 1; i <= k; i++) {
        st.insert(c[i]);
    }
    for(int i = 1; i <= k; i++) {
        if(st.find(b[i]) == st.end()) cnt++;
    }
    if(cnt == 0) return k;
    else return cnt;
}
int main() {
    int t; cin >> t;
    while(t--) {
        ktao();
        if(ok) {
            sinh();
            for(int i = 1; i <= k; i++) b[i] = a[i];
        }
        cout << check();
        cout << endl;
    }   
}