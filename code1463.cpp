#include <iostream>

int calculate(int tem);
int smallest(int a, int b, int c);
int smaller(int a, int b);
int save[1000001];
int main() {
	int x=0;

	int count=0;
	/*
	int tem = 0;
	int min = 0;
	tem = x;
	int i = 0;
	for (i = 0; i<x; i++) {
		count = i;
		tem = x - i;
		while (tem != 1) {
			if (tem % 3 == 0) tem = tem / 3;
			else if (tem % 2 == 0) tem = tem / 2;
			else tem = tem - 1;

			//std::cout << count << "번째 연산 결과 :: " << tem << "\n";
			count++;
		}
		std::cout << i<<"번째 연산 횟수는 "<<count<<"번\n";
		if (i == 0) min = count; //처음은 그냥 넣기
		else if (count < min) min = count; //더 작으면 넣기

	}
	*/
	int i;
	std::cin >> x;
	for (i = 0; i < x; i++) {
		save[i] = -1;
	}

		std::cout << calculate(x);
	return 0;

}

int calculate(int tem) {
	//std::cout << tem << " :: 입장\n";
	if (save[tem] != -1) return save[tem];
	else{
		if (tem == 1 || tem == 2 || tem == 3) {
			//std::cout << tem<<" :: 1나옴\n";
			save[tem] = 1;
			return 1;
		}
		else {
			if (tem % 3 == 0) {
				if (tem % 2 == 0) {
					save[tem]=smallest(calculate(tem / 3), calculate(tem / 2), calculate(tem - 1)) + 1;
					return save[tem];
				}
				else { save[tem] = smaller(calculate(tem / 3), calculate(tem - 1)) + 1;
				return save[tem];
				}
			}
			if (tem % 2 == 0) {
				save[tem] = smaller(calculate(tem / 2), calculate(tem - 1)) + 1;
				return save[tem];
			}
			
			save[tem] = calculate(tem - 1) + 1;
			return save[tem];
			

			
		}
	}
}

int smallest(int a, int b, int c) {
	if (a <b) {
		if (a < c) return a;
		else return c;
	}
	else {
		if (b < c) return b;
		else return c;
	}
}
int smaller(int a, int b) {
	if (a < b) return a;
	else return b;
}