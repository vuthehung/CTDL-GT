#include<bits/stdc++.h>
using namespace std;
bool prime[1000001];
void sang() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i <= sqrt(1000000); i++) {
        if(prime[i]) {
            for(int j = i * i; j <= 1000000; j += i) {
                prime[j] = false;
            }
        }
    }
}
int main() {
    int t; cin >> t;
    sang();
    while(t--) {
        int n; cin >> n;
        bool ok = false;
        for(int i = 1; i <= n / 2; i++) {
            if(prime[i] && prime[n - i]) {
                cout << i << " " << n - i;
                ok = true;
                break;
            }
        }
        if(!ok) cout << "-1";
        cout << endl;
    }
}