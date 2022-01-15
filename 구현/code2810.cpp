#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string seats;

	cin >> n;
	cin >> seats;

	int holder = 1; 
	for (int i = 0; i < n; i++) {
		if (seats[i] == 'S')	holder++;
		if (seats[i] == 'L') {
			i++;
			holder++;
		}
	}

	cout << min(holder,n)<< "\n";

	return 0;
}