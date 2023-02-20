// //1.Tạo mảng vt[i]: vị trí của phần tử i trong mảng ban đầu 
// 2.Cho i chạy từ 1 đến n tìm dãy vt[i] tăng dài nhất 
// 3.Lấy n trừ số phần tử dãy tìm được ở 2

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n + 1];
    int vt[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        vt[a[i]] = i;
    }
    vector<int> v;
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(vt[i] < vt[i + 1]) {
            cnt++;
            v.push_back(cnt);
        }else {
            cnt = 1;
        }
    }
    int x = *max_element(v.begin(), v.end());
    cout << n - x;
}