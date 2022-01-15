#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int main() {
	
	cin >> n >> m;
	
	if (n == 1) { cout << 1 << "\n"; }
	else if (n==2) { //오른쪽 2칸만 가능
		cout << min(4, (m + 1) / 2);
	}
	else if (m<=6){ //모든 방법 이용 불가능,4번이 넘더라도 4번까지만 이동
		cout << min(4, m);
	}
	else { //2만큼 2번 움직이고 나머지는 다 1칸씩만 이동
		cout << m - 2 << "\n";
	}
	return 0;
}