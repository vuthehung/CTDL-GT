#include <iostream>
#include <vector>
using namespace std;

long long max_pairwise_product(vector<int> v) {
	long long result = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (result < (long long) v[i] * v[j]) {
				result = (long long) v[i] * v[j];
			}
		}
	}
	return result;
}

long long max_pairwise_product2(vector<int> v) {
	int max_index1 = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > v[max_index1]) {
			max_index1 = i;
		}
	}
	int max_index2 = -1;
	for (int i = 0; i < v.size(); i++) {
		if (i != max_index1 && (max_index2 == -1 || v[i] > v[max_index2])) {
			max_index2 = i;
		}
	}
	long long result = (long long) v[max_index1] * v[max_index2];
	return result;
}

int main() {
	while (true) {
		int n = rand() % 10 + 2;
		cout << n << endl;
		vector<int> a;
		for (int i = 0; i < n; i++) {
			a.push_back(rand() % 100);
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		long long result1 = max_pairwise_product(a);
		long long result2 = max_pairwise_product2(a);
		if (result1 == result2) {
			cout << "OK" << endl;
		} else {
			cout << "WA r1: " << result1 << ", r2: " << result2 << endl;
			break;
		}
	}
//	int n;
//	cin >> n;
//	vector<int> v(n);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//	long long result = max_pairwise_product(v);
	long long result = max_pairwise_product2(vector<int>(100000, 0));
	cout << result;
}
