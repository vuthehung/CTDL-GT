#include<bits/stdc++.h>
using namespace std;


/* cac buoc thuat toan korasaju
B1: duyet DFS1 cua do thi ban dau(G) va luu vao trong stack(tuc theo thu thu topo)
B2: xay dung do thi transpose graph(TG)
B3: goi DFS2 den dinh o dau ngan xep! va cac dinh duoc tham tu DFS se la thanh phan lien thong manh
*/
int n, m;
vector<int> adj[1001];
vector<int> r_adj[1001]; // luu tranpose graph
bool used[1001];
stack<int> st;

void inp() {
	for(int i = 1; i <= n; i++) {
		adj[i].clear();
		r_adj[i].clear();
	}
	while(!st.empty()) st.pop();
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		r_adj[y].push_back(x);
	}
}
void dfs1(int u) {
	used[u] = true;
	for(int x : adj[u]) {
		if(!used[x]) {
			dfs1(x);
		}
	}
	st.push(u);
}
void dfs2(int u) {
	used[u] = true;
	cout << u << " ";
	for(int x : r_adj[u]) {
		if(!used[x]) {
			dfs2(x);
		}
	}
}

void SCC() {
	memset(used, false, sizeof(used));
	for(int i = 1; i <= n; i++) {
		if(!used[i]) {
			dfs1(i);
		}
	}
	memset(used, false, sizeof(used));
	int cnt = 0;
	while(!st.empty()) {
		int t = st.top(); st.pop();
		if(!used[t]) {
			dfs2(t);
			cnt++;
			cout << endl;
		}
	}
	if(cnt == 1) cout << "YES\n";
	else {
		cout << "NO " << cnt << endl;
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		SCC();
	}
}
