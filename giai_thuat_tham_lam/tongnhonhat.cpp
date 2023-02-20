/* 
cho mang A gom cac ptu tu 0 -> 9
tu cac ptu mang A: chia cac ptu de tao thanh 2 so
=> tim tong nho nhat cua 2 so dc tao
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        string num1 = "";
        string num2 = "";
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                num1 += to_string(a[i]);
            }else {
                num2 += to_string(a[i]);
            }
        }
        long long ans = 0;
        ans = stoll(num1) + stoll(num2);
        cout << ans << endl;
    }
}