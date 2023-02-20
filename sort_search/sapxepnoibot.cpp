#include<bits/stdc++.h>
using namespace std;
void sort4(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        bool ok = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                ok = true;
            }
        }
        if(ok) {
            cout << "Buoc " << i + 1 << ": ";
            for(int i = 0; i < n; i++) cout << a[i] << " ";
            cout << endl;
        }else break;
    }
}
int main() {
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    sort4(a, n);
}
/*
duyệt nếu cặp kế tiếp khác thứ tự thì đổi chỗ cho nhau
*/