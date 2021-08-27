#include <iostream>
#define MAXSIZE 1000001
using namespace std;

int main() {
	int m, n;
	cin >> m;
	cin >> n;

	int array[MAXSIZE] = { 0, };

	for (int i = 2; i <= n; i++) {
		for (int j = 1; i*j <= n; j++) {
			array[i*j]++;
			//cout << i * j << " : " << array[i*j]<<"\n";
		}
	}

	//cout << "°á°ú ----------" << "\n";
	for (int i = m; i <= n; i++) {
		if (array[i]==1) cout << i<<"\n";
	}
}