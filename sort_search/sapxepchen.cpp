#include<bits/stdc++.h>
using namespace std;
void sort3(int a[], int n) {
    for(int i = 0; i < n; i++) {
        int x = a[i], pos = i - 1;
        while(pos >= 0 && x < a[pos]) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
        cout << "Buoc " << i << ": ";
        for(int j = 0; j <= i; j++) cout << a[j] << " ";
        cout << endl;
    }
}
int main() {
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    sort3(a, n);
}

/*
bước 1: chọn a1
bước 2: chọn tiếp a2 nếu a2 > a1 thì a2 đứng trc a1. ko thì a2 đứng sau a1;
....
*/