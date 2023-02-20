#include<bits/stdc++.h>
using namespace std;
void sort1(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
        cout << "Buoc " << i + 1 << ": ";
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
}
int main() {
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    sort1(a, n);
}