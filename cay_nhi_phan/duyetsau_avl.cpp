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
Node* build_avl(int a[], int l, int r) {
	if(l > r) return NULL;
	int m = (l + r) / 2;
	Node *root = new Node(a[m]);
	root->left = build_avl(a, l, m - 1);
	root->right = build_avl(a, m + 1, r);
	return root;
}
void postOrder(Node *root) {
	if(root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		Node *root = build_avl(a, 0, n - 1);
		postOrder(root);
		cout << endl;
	}
}
