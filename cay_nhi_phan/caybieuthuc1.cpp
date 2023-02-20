#include<bits/stdc++.h>
using namespace std;

struct Node{
	char val;
	Node *left, *right;
	Node(char c) {
		val = c;
		left = right = NULL;
	}
};

//duyet giua: node dinh in ra o giua
void inOder(Node *root) {
	if(root == NULL) return;
	inOder(root->left);
	cout << root->val;
	inOder(root->right);
}
//duyet truoc: node dinh in dau
void preOder(Node *root) {
	if(root == NULL) return;
	cout << root->val;
	preOder(root->left);
	preOder(root->right);
}
//duyet sau: node dinh in cuoi
void postOrder(Node *root) {
	if(root == NULL) return;
	posOrder(root->left);
	posOrder(root->right);
	cout << root->val;
}
//ktra ki tu la operator
bool check(char s) {
	return s == '+' || s == '-' || s == '*' || s == '/';
}
void solve(string s) {
	stack<Node* > st;
	Node *root;
	for(int i = 0; i < s.length(); i++) {
		if(!check(s[i])) {
			st.push(new Node(s[i]));
		}else {
			Node *tmp = new Node(s[i]);
			Node *top1 = st.top(); st.pop();
			Node *top2 = st.top(); st.pop();
			tmp->left = top2;
			tmp->right = top1;
			st.push(tmp);
		}
	}
	root = st.top();
	inOder(root);
}
int main() {
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		solve(s);
		cout << endl;
	}
}
