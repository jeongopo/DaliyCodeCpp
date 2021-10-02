#include <iostream>
#include <cmath>
using namespace std;

int n;

void movePlateFromTo(int from,int middle, int to,int count) {
	
	if (count == 1) {
		cout << from << " " << to << "\n";
		return;
	}

	movePlateFromTo(from, to, middle, count -1);
	cout << from << " " << to << "\n";
	movePlateFromTo(middle, from, to, count -1);

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	cout << (int)pow(2, n) - 1 << "\n";
	movePlateFromTo(1, 2,3,n);

	return 0;
}