#include <iostream>
using namespace std;
int main() {
	long long n;
	cin>>n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int q = 2;
	while (n >1) {
		if (n%q == 0) {
			cout << q << "\n";
			n = n / q;
		}
		else { //나누어지지 않으면 다음 숫자로(낮은 수부터 하므로 모두 소수)
			q++;
		}
	}
	return 0;
}