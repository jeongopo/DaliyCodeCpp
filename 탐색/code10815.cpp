#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cards;
int n,m;

void findCard(int FindNum) {
	int right = n-1, left = 0;
	int mid = 0;
	
	while (left <= right) {
		mid = (left + right) / 2;

		if (FindNum > cards[mid]) {
			left = mid+1;
		}
		else if (FindNum < cards[mid]) {
			right = mid-1;
		}
		else if(FindNum==cards[mid]){
			cout << 1 << " ";
			return;
		}
	}
	cout << 0 << " ";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int Input;
		cin >> Input;
		cards.push_back(Input);
	}

	sort(cards.begin(), cards.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int FindInput = 0;
		cin >> FindInput;
		findCard(FindInput);
	}
	
	cout << "\n";
	return 0;
}