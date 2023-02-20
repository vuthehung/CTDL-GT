#include<bits/stdc++.h>
using namespace std;
int n, m;
bool used[1001];
vector<int> ke[1001];
/* 1 so ham cua queue:
+   push(): day vao
+   empty(): tra TRUE neu queue rong
+   front(): lay ra phan tu o dau hang doi
+   pop(): xoa phan tu o dau hang doi 
*/
void bfs(int u) {
    // b1: ktao: khoi tao 1 hang doi queue, day dinh u vao queue;
    queue<int> q;
    q.push(u);
    used[u] = true; // dinh u da duoc tham.
    while(!q.empty()) {
        int s = q.front(); // lay ra dinh o dau hang doi;
        q.pop(); // xoa dinh s;
        cout << s << " "; // tham dinh s;
        for(int t : ke[s]) {
            if(used[t] == false) { // kiem tra xem dinh nao chua duoc tham
                q.push(t);         // day t vao hang doi
                used[t] = true;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        //ke[y].push_back(x);
    }
    memset(used, false, sizeof(used));
    bfs(1);
    return 0;
}
