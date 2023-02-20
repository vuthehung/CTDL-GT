#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int r) {
    int i = l - 1;
    int x = a[r];
    for(int j = l; j <= r - 1; j++) {
        if(a[j] < x) {
            i++; // de chi so i nhay sang phan tu lon hon x
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[r]);
    return i;
}
void quickSort(int a[], int l, int r) {
    if(l >= r) return;
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    quickSort(a, 0, n - 1);
    for(int x : a) cout << x << " ";
}