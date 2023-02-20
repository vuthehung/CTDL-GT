#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    vector<int> c;
    vector<int> l;
    for(int i = 0; i < n; i++) {
        if((i + 1) % 2 == 0) {
            c.push_back(a[i]);
        }else if((i + 1) % 2 != 0){
            l.push_back(a[i]);
        }
    }
    sort(c.begin(), c.end(), greater<int>());
    sort(l.begin(), l.end());
    int j = 0, k = 0;
    for(int i = 0; i < n; i++) {
        if((i + 1) % 2 == 0) {
            a[i] = c[j++];
        }else if((i + 1) % 2 != 0){
            a[i] = l[k++];
        }
    }
    for(int x : a) cout << x << " ";
}