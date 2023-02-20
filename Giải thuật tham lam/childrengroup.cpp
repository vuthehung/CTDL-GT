// tao nhom it nhat co so tre em chenh lech ko qua 1 tuoi

#include<bits/stdc++.h>
using namespace std;
int optimine_group(vector<float> children) {
    sort(children.begin(), children.end());
    int number_group = 0;
    int i = 0;
    while(i < children.size()) {
        int l = children[i]; 
        int r = l + 1; // chenh lech lon nhat la 1 tuoi
        number_group++;
        i++;
        while(i < children.size() && children[i] <= r) i++;
    }
    return number_group;
}
int main() {
    int n; cin >> n;
    vector<float> children(n);
    for(size_t i = 0; i < children.size(); i++) {
        cin >> children[i];
    }
    int number_group = optimine_group(children);
    cout << number_group;
}