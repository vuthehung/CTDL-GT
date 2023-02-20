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
Node* build_bst(int pre[], int *idx, int l, int r, int n) {
	if(*idx >= n || l > r) return NULL;
	Node *root = new Node(pre[*idx]);
	(*idx)++;
	if(l == r) return root;
	int ans;
	for(int i = l; i <= n; i++) {
		if(pre[i] > root->val) {
			ans = i;
			break;
		}
	}
	root->left = build_bst(pre, idx, *idx, ans - 1, n);
	root->right = build_bst(pre, idx, ans, r, n);
	return root;
}
int height(Node *root) {
	if(root == NULL) return -1;
	return 1 + max(height(root->left), height(root->right));
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int pre[n];
		for(int i = 0; i < n; i++) cin >> pre[i];
		int idx = 0;
		Node *root = build_bst(pre, &idx, 0, n - 1, n);
		cout << height(root) << endl;
	}
}
