#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node *left, *right; //*: con tro
	Node(int x) {
		val = x;
		left = right = NULL; //node con ben trai, phai = NULL
	}
};

void makeNode(Node *root, int u, int v, char c) {
	if(c == 'L') root->left = new Node(v);
	else root->right = new Node(v);
}
//Ham them 1 node vao cay
void insert(Node *root, int u, int v, char c) {
	if(root == NULL) return;
	if(root->val == u) {
		makeNode(root, u, v, c);
	}
	insert(root->left, u, v, c);
	insert(root->right, u, v, c);
}
//Tra ve chieu cao cua cay
int height(Node *root) {
	if(root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}
//kiem tra muc cua node la
bool check(Node *root, int level, int h) { // level: muc cua node dang xet, h: chieu cao cau cay
	if(root == NULL) return true;
	if(root->left == NULL && root->right == NULL && level < h)
		return false;
	return check(root->left, level + 1, h) && check(root->right, level + 1, h);
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		Node *root = NULL;
		while(n--) {
			int u, v; 
			char x;
			cin >> u >> v >> x;
			if(root == NULL) {
				root = new Node(u);
				makeNode(root, u, v ,x);
			}else {
				insert(root, u, v, x);
			}
		}
		int h = height(root);
		if(check(root, 1, h)) {
			cout << 1 << endl;
		}else {
			cout << 0 << endl;
		}
	}
}
