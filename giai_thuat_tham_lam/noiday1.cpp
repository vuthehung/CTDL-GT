#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main() {
    int t; cin >> t;
    while(t--) {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            q.push(x);
        }
        long long ans = 0;
        while(q.size() > 1) {
            long long top1 = q.top(); q.pop();
            long long top2 = q.top(); q.pop();
            ans += (top1 + top2);    
            q.push(top1 + top2);    
        }
        cout << ans << endl;
    }
}