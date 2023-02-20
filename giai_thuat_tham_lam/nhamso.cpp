// duoc doi tu 5 -> 6 va 6 -> 5. Tinh tong nho nhat va lon nhat

#include<bits/stdc++.h>
using namespace std;
void sumMin(string a, string b) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == '6') a[i] = '5';
    }
    for(int i = 0; i < b.size(); i++) {
        if(b[i] == '6') b[i] = '5';
    }
    cout << stoi(a) + stoi(b) << " ";
}
void sumMax(string a, string b) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == '5') a[i] = '6';
    }
    for(int i = 0; i < b.size(); i++) {
        if(b[i] == '5') b[i] = '6';
    }
    cout << stoi(a) + stoi(b);
}
int main() {
    string a, b;
    cin >> a >> b;
    sumMin(a, b);
    sumMax(a, b);
}