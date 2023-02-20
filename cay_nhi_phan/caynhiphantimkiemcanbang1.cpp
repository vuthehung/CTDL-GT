#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node *left, *right;
	Node(int x) {
		val = x;
		left = right = NULL;
	}
};
Node* build_val(int a[], int l, int r) {
	if(l > r) return NULL;
	int m = (l + r) / 2;
	Node *root = new Node(a[m]);
	root->left = build_val(a, 0, m - 1);
	root->right = build_val(a, m + 1, r);
	return root;
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int m = (n - 1) / 2;
		cout << a[m] << endl;
	}
}
