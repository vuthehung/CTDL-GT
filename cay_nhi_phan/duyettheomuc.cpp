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

void levelOrder(Node *root) {
	queue<Node* > q;
	q.push(root);
	while(!q.empty()) {
		Node *top = q.front(); q.pop();
		cout << top->val << " ";
		if(top->left != NULL) q.push(top->left);
		if(top->right != NULL) q.push(top->right);
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
		levelOrder(root);
		cout << endl;
	}
}
