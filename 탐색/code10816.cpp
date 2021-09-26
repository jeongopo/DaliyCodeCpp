#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> cards;
	int n, m;

	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tem;
		cin >> tem;
		cards.push_back(tem);
	}

	sort(cards.begin(),cards.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int tem;
		cin >> tem;

		auto upper = upper_bound(cards.begin(), cards.end(), tem);
		auto lower = lower_bound(cards.begin(), cards.end(), tem);

		cout << upper - lower<<" ";
	}
	cout << "\n";

	return 0;
}