// /*
//  Đồ thị vô hướng:
// - Có chu trình euler: tất cả các đỉnh có bậc chẵn
// - Có đường đi euler: nếu tồn tại 2 đỉnh duy nhất có bậc lẻ, và đường đi sẽ bắt đầu và kết thúc ở đỉnh lẻ đó.
//  Đồ thị có hướng:
//  -Có chu trình euler: bán bậc vào = bán bậc ra
//  -Có đường đi euler: nếu tồn tại duy nhất 2 đỉnh mà có độ lệch giữa bán bâc ra và vào  = 1;
//  => đỉnh có bán bậc ra = bán bậc vào + 1: đỉnh bắt đầu, đỉnh có bán bậc vào = bán bậc ra + 1: kết thúc.
// Các bước tìm chu trình euler:
//     -B1: tạo stack
//         đẩy đỉnh bắt đầu vào stack
//     -B2: Lặp khi mà stack còn chưa rỗng
//         + lấy phần tử ở đỉnh stack là u
//         + nếu u không còn đỉnh kề thì xoá u khỏi stack, đưa u vào chu trình
//         + nếu u còn đỉnh kề: đẩy đỉnh kề đầu tiên của u là v vào stack, và xoá cạnh (u, v) khỏi đồ thị.
// */

// #include<bits/stdc++.h>
// using namespace std;
// int a[1001][1001];
// int n, m, degree[1001];
// set<int> adj[1001]; // dung set de luu danh sach ke
// void init() {
//     cin >> n >> m; // so dinh va so canh
//     for(int i = 1; i <= m; i++) {
//         int x, y; cin >> x >> y; // nhap cac canh
//         a[x][y] = a[y][x] = 1;
//         adj[x].insert(y);
//         adj[y].insert(x);
//         degree[x]++; degree[y]++;
//     }
// }
// void euler_cycle1(int u) { // cach 1: xoa canh bang ma tran ke
//     for(int i = 1; i <= n; i++) {
//         if(degree[i] % 2 == 1) {
//             cout << "khong co chu trinh euler";
//             return;
//         }
//     }
//     stack<int> st;
//     st.push(u);
//     vector<int> cycle;
//     while(!st.empty()) {
//         int u = st.top();
//         int ok = 1; // ktra: ko con dinh ke ok = 1, co dinh ke ok = 0;
//         for(int i = 1; i <= n; i++) {
//             if(a[u][i] == 1) {
//                 st.push(i);
//                 a[u][i] = a[i][u] = 0;
//                 ok = 0; break;
//             }
//         }
//         if(ok) {
//             st.pop();
//             cycle.push_back(u);
//         }
//     }
//     for(int x : cycle) {
//         cout << x << " ";
//     }
// }
// void euler_cycle2(int u) { // dung ham erase cua set de xoa canh
//     for(int i = 1; i <= n; i++) {
//         if(degree[i] % 2 == 1) {
//             cout << "khong co chu trinh euler";
//             return;
//         }
//     }
//     stack<int> st;
//     st.push(u);
//     vector<int> cycle;
//     while(!st.empty()) {
//         int u = st.top();
//         if(adj[u].size() != 0){
//             int v = *adj[u].begin(); // ptu dau tien trong ds ke cua u
//             st.push(v);
//             adj[u].erase(v);
//             adj[v].erase(u);
//         }
//         else{
//             st.pop();
//             cycle.push_back(u);
//         }
//     }
//     for(int x : cycle) {
//         cout << x << " ";
//     }
// }
// int main() {
//     init();
//     euler_cycle1(1);
//     cout << endl;
//     euler_cycle2(1);
// } 

#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int n, m, s, degree[100];
set<int> adj[100];
void init() {
    cin >> n >> m;
    for(int k = 0; k < m; k++) {
        int i, j; cin >> i >> j;
        adj[i].insert(j);
        adj[j].insert(i);
        degree[i]++; degree[j]++;
    }
}
void euler_cycle(int u) {
//    for(int i = 1; i <= n; i++) {
//        if(degree[i] % 2 == 1) {
//            cout << "no Euler Cycle";
//            return;
//        }
//    }
    stack<int> st;
    st.push(u);
    vector<int> cycle;
    while(!st.empty()) {
        int u = st.top();
        if(adj[u].size() != 0) {
            int v = *adj[u].begin();
            st.push(v);
            adj[u].erase(v);
            adj[v].erase(u);
        }else {
            st.pop();
            cycle.push_back(u);
        }
        
    }
    reverse(cycle.begin(), cycle.end());
    for(int x : cycle) {
            cout << x << " ";
        }
}
int main() {
    init();
    euler_cycle(4);
}
