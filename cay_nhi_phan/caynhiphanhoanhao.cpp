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
//cay nhi phan hoan hao: moi node trung gian co 2 node con va cac node la co cung muc

//tra ve chieu cao cau cay
int height(Node *root) {
	if(root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}
//kiem tra node la co cung muc hay khong
bool check1(Node *root, int level, int h) {
	if(root == NULL) return true;
	if(root->left == NULL && root->right == NULL && level < h) 
		return false;
	return check1(root->left, level + 1, h) && check1(root->right, level + 1, h);
}
//kiem tra node trung gian co 2 node con hay ko
bool check2(Node *root) {
	if(root == NULL) return true;
	//truong hop node con cua node trung gian bi lech 1 ben
	if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
		return false;
	return check2(root->left) && check2(root->right);
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
		int h = height(root);
		if(check1(root, 1, h) && check2(root)) {
			cout << "Yes\n";
		}else {
			cout << "No\n";
		}
	}
}
