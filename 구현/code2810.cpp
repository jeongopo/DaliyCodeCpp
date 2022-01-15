#include <iostream>
#include <string>
using namespace std;

/*
	알고리즘 스터디 2주차 3번문제 남현정
	2810 : 컵홀더

	[문제풀이 과정]
	- 문제는 길었지만 결국 일반좌석이 있다면 그 옆에는 반드시 컵홀더가 하나 있고, 커플좌석이 있다면 그 사이에는 없다는 것.
	- 그리고 컵홀더의 개수만 구해주면 된다.
	- 왼쪽에서 오른쪽으로 좌석을 나아가면서
	일반 좌석이면 -> 바로 옆자리에 컵홀더가 있으므로 컵홀더 개수를 늘려준다
	커플 좌석이면 -> 옆자리엔 컵홀더가 없으므로, 오른쪽으로 한칸 더 이동한 후에 컵홀더 개수를 늘려준다.
	- LLLLLL 처럼 사람 수는 6명이지만 컵홀더가 4개밖에 없는 경우, 더 작은 값인 컵홀더 값을 결괏값으로 택하기 때문에 min(컵홀더,좌석수) 값을 출력해준다
*/

int main() {
	int n;
	string seats;

	cin >> n;
	cin >> seats;

	int holder = 1; 
	for (int i = 0; i < n; i++) {
		if (seats[i] == 'S')	holder++;
		if (seats[i] == 'L') {
			i++;
			holder++;
		}
	}

	cout << min(holder,n)<< "\n";

	return 0;
}