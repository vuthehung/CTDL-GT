#include<bits/stdc++.h>
using namespace std;

//struct Node{
//	int val;
//	Node *left, *right;
//	Node(int x) {
//		val = x;
//		left = right = NULL;
//	}
//};

//tim vi tri node trung gian trong mang inOrder thong qua mang preOrder
int search(int in[], int x, int n) {
	for(int i = 0; i < n; i++) {
		if(in[i] == x) 
			return i;
	}
	return -1;
}
void postOrder(int in[], int pre[], int n) {
	int root = search(in, pre[0], n);
	if(root != 0) { //co cay con ben trai
		postOrder(in, pre + 1, root);
	} 
	if(root != n - 1) { //co cay con ben phai
		postOrder(in + root + 1, pre + root + 1, n - root - 1);
	}
	cout << pre[0] << " ";
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int in[n], pre[n];
		for(int i = 0; i < n; i++) cin >> in[i];
		for(int i = 0; i < n; i++) cin >> pre[i];
		postOrder(in, pre, n);
		cout << endl;
	}
	
}
