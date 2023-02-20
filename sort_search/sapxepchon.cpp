#include<bits/stdc++.h>
using namespace std;
void sort2(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int x = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[x]) {
                x = j;
            }
        }
        if(x != i) swap(a[i], a[x]);
        cout << "Buoc " << i + 1 << ": ";
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
}
int main() {
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    sort2(a, n);
}

/*
ở lượt 1: chọn ptu nhỏ nhất đổi chỗ cho a1;
ở lượt 2: chọn ptu nhỏ nhất đổi chỗ cho a2;
....
*/

// void selectionSort(int a[], int n) {
//     for(int i = 0; i < n - 1; i++) {
//         int min_idx = i;
//         for(int j = i + 1; j < n; j++) {
//             if(a[j] < a[min_idx]) {
//                 min_idx = j;
//             }
//         }
//         if(min_idx != i) swap(a[min_idx], a[i]);
//     }
// }
// int main() {
// }