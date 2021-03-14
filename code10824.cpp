#include <iostream>
#include <string>
using namespace std;
void solution() {
	string a, b, c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;

	a.append(b);
	c.append(d);

	//cout << a << ", " << c << "\n";
	cout << stoll(a)+stoll(c) << "\n";

}

int main() {
	solution();
	return 0;
}
