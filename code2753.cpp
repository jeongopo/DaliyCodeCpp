#include <iostream>

int main() {
	//백준 2753
	//연도가 4의 배수이면서, 100의 배수가 아닐때, 400의 배수일 때 윤년
	int year;
	while (1) {
		std::cout << "년도를 입력하세요\n";
		std::cin >> year;

		if (year % 400 == 0) {
			std::cout << "400의 배수이기 때문에 윤년\n";
		}
		else if (year % 4 == 0 && year % 100 != 0) {
			std::cout << "100의 배수가 아니면서 4의 배수이기 때문에 윤년\n";
		}
		else {
			std::cout << "윤년 아님\n";
		}
	}


	return 0;
}