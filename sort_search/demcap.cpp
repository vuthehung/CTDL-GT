/* dem cac cap (x, y) sao cho x^y > y^x
    ta co x < y => x^y > y^x
    tru 1 so truong hop ngoai le:
    +) x = 2, y = 3
    +) x = 2, y = 4
    +) x = 3, y = 2
*/
#include<bits/stdc++.h>
using namespace std;

int cnt[5]; // dem cac phan tu 0, 1, 2, 3, 4 xuat hien trong mang b;
//vi tri dau tien > x;
int first_pos(int a[], int l, int r, int x) {
    int res = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid] > x) {
            res = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    return res;
}
// dem cac cap thoa ma de bai
int dem(int b[], int m, int x) {
    if(x == 0) return 0;
    if(x == 1) return cnt[0];
    long long ans = cnt[0] + cnt[1]; // vi so x nao > 1 thi y = (0, 1) deu thoa man.
    int l = first_pos(b, 0, m - 1, x);
    if(l != -1) ans += m - l;
    // kiem tra TH ngoai le.
    if(x == 2) ans -= (cnt[3] + cnt[4]);
    if(x == 3) ans += cnt[2];
    return ans; 
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        int a[n], b[m];
        for(int &x : a) cin >> x;
        for(int i = 0; i < m; i++) {
            cin >> b[i];
            if(b[i] <= 4) cnt[b[i]]++;
        }
        sort(b, b + m);
        long long count = 0;
        for(int i = 0; i < n; i++) {
            count += dem(b, m, a[i]);
        }
        cout << count << endl;
        memset(cnt, 0, sizeof(cnt));
    }
}
