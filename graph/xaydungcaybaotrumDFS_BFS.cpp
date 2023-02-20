#include<bits/stdc++.h>
using namespace std;

#define max 100

class graph{
    int n, s, a[max][max], chuaxet[max];
    public:
        void readdata();
        void init() {
            for(int i = 1; i <= n; i++) {
                chuaxet[i] = 1;
            }
        }
        void stackdfs(int u);
        void queuebfs(int u);
        int gets() {
            return s;
        }
};
void graph :: readdata() {
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}
void graph :: stackdfs(int u) {
    stack<int> st;
    chuaxet[u] = 0;
    st.push(u);
    while(!st.empty()) {
        int s = st.top();
        st.pop();
        for(int t = 1; t <= n; t++) {
            if(a[s][t] == 1 && chuaxet[t] == 1) {
                st.push(s);
                st.push(t);
                chuaxet[t] = 0;
                if(s < t) cout << s << " " << t << endl;
                else cout << t <<  " " << s << endl;
                break;
            }
        }
    }   
}
void graph :: queuebfs(int u) {
    queue<int> q;
    q.push(u);
    chuaxet[u] = 0;
    while(!q.empty()) {
        int s = q.front(); q.pop();
        for(int t = 1; t <= n; t++) {
            if(a[s][t] == 1 && chuaxet[t] == 1) {
                q.push(t);
                chuaxet[t] = 0;
                if(s < t) cout << s << " " << t << endl;
                else cout << t <<  " " << s << endl;
            }
        }
    }
}
int main() {
    graph g;
    g.readdata();
    cout << "DFS tree" << endl;
    g.init();
    g.stackdfs(g.gets());
    cout << "BFS tree" << endl;
    g.init();
    g.queuebfs(g.gets());
}

