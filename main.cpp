#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long int> v(n);

	for (long long int &e : v) cin >> e;

	vector<long long int> u(n + 1);
	long long int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += v[i - 1];
		u[i] = sum;
	}
	u[0] = 0;

	sort(v.begin(), v.end());
	vector<long long int> j(n + 1);
	sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += v[i - 1];
		j[i] = sum;
	}
	j[0] = 0;

	int m;
	cin >> m;

	vector<long long int> a[] = {u, j};

	for (int i = 0; i < m; i++) {
		int l, r, t;
		cin >> t >> l >> r;
		cout << (a[--t][r] - a[t][--l]) << '\n'; 
	}
}
