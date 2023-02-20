#include<bits/stdc++.h>
using namespace std;
// kruskal
struct edge{
	int d, c, w;
};
int n, m;
vector<int> ke[1001];
int size[1001], parent[1001];
vector<edge> canh; // danh sach canh
//size[i]: no luu so dinh thuoc thanh phan lien thong ma i la dinh daij dien
//parent[i]: dinh daij dien cua dinh i
bool cmp(edge x, edge y) {
	return x.w < y.w;
}
void init() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		edge tmp{x, y, w};
		canh.push_back(tmp);
	}
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
		size[i] = 1;
	}
}
int Find(int u) {
	if(u == parent[u]) {
		return u;
	}
	return parent[u] = Find(parent[u]);
}
//
bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if(x == y) return false;
	if(x != y) {
		if(size[x] > size[y]) {
			parent[y] = x;
			size[x] += size[y];
		}else {
			parent[x] = y;
			size[y] += size[x];
		}
	}	
	return true;
}
void kruskal() {
	//
	int d = 0;
	sort(canh.begin(), canh.end(), cmp);
	vector<edge> mst;// cay khung nho nhat
	for(int i = 0; i < m; i++) {
		if(mst.size() == n - 1) break;
		int u = canh[i].d, v = canh[i].c;
		if(Union(u, v) == true) {
			cout << u << " " << v << endl;
			mst.push_back(canh[i]);
			d += canh[i].w;
		}else {
			cout << "khong the gop dc 2 dinh " << u << " va " << v << endl;
		}
	}
	if(mst.size() != n - 1) {
		cout << "Khong lien thong\n";
	}else {
		cout << d << endl;
	}
}
int main() {
	init();
	kruskal();
}
