#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {3, 9, 5, 9, 7, 1};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);
    int result = 0;
    for(int i = n - 1; i >= 0; i--) {
        result = result * 10 + a[i];
    }
    cout << result;
}