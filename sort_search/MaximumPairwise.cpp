#include <iostream>
#include <vector>
using namespace std;

int max_pairwise_product(vector<int> v) {
	int result = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (result < v[i] * v[j]) {
				result = v[i] * v[j];
			}
		}
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int result = max_pairwise_product(v);
	cout << result;
}




