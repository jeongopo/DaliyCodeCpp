
#include <iostream>

int main() {
	int a=0;
	int b = 0;
	int c = 0;

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	int ret = 0;
	if (c>b) ret = a / (c - b) + 1; 
	else ret = -1;
	std::cout << ret;

}