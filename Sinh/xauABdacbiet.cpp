// liet ke xau AB co duy nhat 1 day K bit A lien tiep

#include<bits/stdc++.h>
using namespace std;

int n, k, ok, ans = 0;
int a[100];
void init() {
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
bool check() {
    int cnt = 0, bit0 = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) bit0++;
        else {
            if(bit0 > k) return false;
            else if(bit0 == k) cnt++;
            bit0 = 0;
        }
    }
    if(a[n] == 0) {
        if(bit0 > k) return false;
        else if(bit0 == k) cnt++;
    }
    return cnt == 1;
}
int main() {
    cin >> n >> k;
    init();
    ok = 1;
    vector<string> v;
    while(ok) {
        if(check()) {
            ans++;
            string tmp = "";
            for(int i = 1; i <= n; i++) {
                if(a[i] == 1) tmp += "B";
                else tmp += "A";
            }
            v.push_back(tmp);
        }
        sinh();
    }
    cout << ans << endl;
    for(string s : v) cout << s << endl;
}