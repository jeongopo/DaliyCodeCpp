#include <iostream>

int main() {
	int a;
	int b;
	int t;

	std::cin >> t;
	int i;
	int ret[100];
	for (i = 0; i < t; i++) {
		std::cin >> a;
		std::cin >> b;
		//std::cout << i << "번째 Test, a:: " << a << ", b::" << b << "\n";
		ret[i] = a + b;
	}
	for (i = 0; i < t; i++) {
		std::cout << ret[i] << "\n";
	}
}