/* 
Một dãy xâu ký tự G chỉ bao gồm các chữ cái A và B được gọi là dãy xâu Fibonacci nếu
thỏa mãn tính chất: G(1) = A; G(2) = B; G(n) = G(n-2)+G(n-1). Với phép cộng (+) là
phép nối hai xâu với nhau. Bài toán đặt ra là tìm ký tự ở vị trí thứ i (tính từ 1) của xâu
Fibonacci thứ n.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fibo[100];
void init() {
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i <= 92; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}
char timkiem(int n, ll i) {
    if(n == 1) return 'A';
    else if(n == 2) return 'B';
    if(i <= fibo[n - 2]){
        return timkiem(n - 2, i);
    }else return timkiem(n - 1, i - fibo[n - 2]);
}
int main() {
    int t; cin >> t;
    init();
    while(t--) {
        ll n, i; cin >> n >> i;
        cout << timkiem(n, i) << endl;
    }
}