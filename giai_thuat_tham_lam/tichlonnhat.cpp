//sắp xếp lại mảng, 
// so sánh 4 cái tích sau: 2 số nhỏ nhất, 2 số lớn nhất, 3 số lớn nhất, 2 số nhỏ nhất với số lớn nhất là ra 

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int res1 = a[0] * a[1];
    int res2 = a[n - 2] * a[n - 1];
    int res3 = a[n - 3] * a[n - 2] * a[n - 1];
    int res4 = a[0] * a[1] * a[n - 1];
    int ans = max(res1, max(res2, max(res3, res4)));
    cout << ans; 
}