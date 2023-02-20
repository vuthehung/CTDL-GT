#include<bits/stdc++.h>
using namespace std;
// void solve() {
//     int n; cin >> n;
//     vector<pair<int, int>> a(n);
//     for(int i = 0; i < n; i++) {
//         int x; cin >> x;
//         a[i].first = x;
//         a[i].second = i;
//     }
//     sort(a.begin(), a.end());
//     int ans = 0;
//     for(int i = 0; i < n; i++) {
//         if(a[i].second != i) {
//             swap(a[i].first, a[a[i].second].first);
//             swap(a[i].second, a[a[i].second].second);
//             if(a[i].second != i) i--;
//             ans++;
//         }
//     }
//     cout << ans << endl;
// }
// int main() {
//     int t; cin >> t;
//     while(t--) {
//         solve();
//     }
// }
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    int t; 
    cin >> t; 
    while(t--){ 
        int n , dem = 0; 
        cin >> n; 
        int a[n]; 
        for(int i = 0 ; i < n ; i++){ 
            cin >> a[i]; 
        } 
        for(int i = 0 ; i < n ; i++){ 
            int min = a[i]; 
            int m = 0; 
            for(int j = i + 1 ; j < n ; j++){ 
                if(a[j] < min){ 
                    min = a[j]; 
                    m = j; 
                } 
            } 
            if(a[i] > min ){ 
                swap(a[i],a[m]); 
                dem++; 
            } 
        } 
        cout << dem << endl;
        }
}