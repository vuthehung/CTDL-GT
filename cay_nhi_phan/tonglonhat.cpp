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
void makeNode(Node *root, int u, int v, char c) {
	if(c == 'L') root->left = new Node(v);
	else root->right = new Node(v);
}
void insert(Node *root, int u, int v, char c) {
	if(root == NULL) return;
	if(root->val == u) makeNode(root, u, v, c);
	insert(root->left, u, v, c);
	insert(root->right, u, v, c);
}
//ham tra ve gia tri lon nhat tu Node la nay sang Node la khac
int maxSum(Node *root, int &ans) {
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL) {
		return root->val;
	}
	int l = maxSum(root->left, ans);
	int r = maxSum(root->right, ans);
	if(root->left != NULL && root->right != NULL) {
		ans = max(ans, l + r + root->val);
		return max(l, r) + root->val;
	}
	if(root->left == NULL) {
		return r + root->val;
	}
	if(root->right == NULL) {
		return l + root->val;
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		Node *root = NULL;
		while(n--) {
			int u, v; char x;
			cin >> u >> v >> x;
			if(root == NULL) {
				root = new Node(u);
				makeNode(root, u, v, x);
			}else {
				insert(root, u, v, x);
			}
		}
		int ans = -1e9;
		maxSum(root, ans);
		cout << ans << endl;
	}	
}
