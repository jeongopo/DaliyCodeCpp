#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> session;

bool cmp(pair<int,int> x, pair<int,int> y) {
	if (x.second == y.second) {
		return x.first < y.first;
	}
	return x.second < y.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int x, y;
	int ret = 1;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		session.push_back(make_pair(x, y));
	}
	if (n == 1) {
		cout << 1 << "\n";
		return 0;
	}

	sort(session.begin(), session.end(),cmp);

	int now_end=session[0].second;
	for (int i = 1; i < n; i++) {
		if (now_end <=session[i].first) {
			ret++;
			now_end = session[i].second;
		}
	}

	cout << ret << "\n";
	return 0;
}