#include<bits/stdc++.h>
using namespace std;
int x[1001];
int b[1001];
int cnt = 0;
void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << x[a[i] - 1] << " ";
    }
    cout << endl;   
}
void sinh(int k, int n) {
    int a[n];
    for(int i = 0; i < k; i++) {
        a[i] = i + 1;
    }
    bool hasNext = true;
    while(hasNext) {
        printArray(a, k);
        int i = k - 1;
        while(i >= 0 && a[i] == n - k + i + 1) {
            i--;
        }
        if(i >= 0) {
            a[i]++;
            for(int j = i + 1; j <= k; j++) {
                a[j] = a[i] + j - i;
            }
        }else hasNext = false;
    }
}
int main() {
    int n, k; 
    cin >> n >> k;
    set<int> st;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        st.insert(b[i]);
    }
    for(int it : st) {
        x[cnt] = it;
        cnt++;
    }
    sinh(k, cnt);
}