#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, pair<int, int> > > edge;
int parent[1005], size[1005];

int find(int x) {
	if(x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
bool unionn(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return false;
	if(size[x] < size[y]) swap(x, y);
	parent[y] = x;
	size[x] += size[y];
	return true;
}
void inp() {
	edge.clear();
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
		size[i] = 1;
	}
	for(int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		edge.push_back(make_pair(w, make_pair(u, v)));
	}
}
void kruskal() {
	int mst_cost = 0;
	sort(edge.begin(), edge.end());
	int cnt = 0, i = 0;
	vector<pair<int, pair<int, int> > > mst;
	while(cnt < n - 1 && i < m) {
		pair<int, pair<int, int> > canh = edge[i++];
		if(unionn(canh.second.first, canh.second.second)) {
			mst.push_back(canh);
			mst_cost += canh.first;
			cnt++;
		}
	} 
	if(mst.size() != n - 1) {
		cout << "Khong lien thong\n";
	}else {
		for(auto it : mst) {
			cout << it.first << " " << it.second.first << " " << it.second.second;
			cout << endl;
		}
		cout << mst_cost << endl;
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		inp();
		kruskal();
	}
}
