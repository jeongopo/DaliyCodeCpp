#include <iostream>
#include <string>
using namespace std;

int main() {
	string array;
	int i=0;
	int count=0;
	int change=0;
	getline(cin,array);
	for (i = 0; i < array.length(); i++) {
		if (array[i] == ' ') {
			if (change == 1) {
				change = 0;
			}
		}
		else {
			if (change == 0) {
				change = 1;
				count++;
			}
		}
	}

	std::cout << count;
	return 0;
}