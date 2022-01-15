#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int e, s, m;
	cin >> e >> s >> m;

	int ret = 1;
	int x=1, y=1, z=1;
	while(1) {
		if (x == e && y == s && z == m)	break;
		x++;
		y++;
		z++;
		ret++;
		if (x > 15)	x = 1;
		if (y > 28)	y = 1;
		if (z > 19)	z = 1;
	}
	cout << ret << "\n";

	return 0;
}