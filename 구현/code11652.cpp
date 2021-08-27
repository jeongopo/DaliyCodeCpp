#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int x, int y) {
	return x < y;
}

void solution() {
	int n;
	cin >> n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long> arr;
	long long tem;
	for (int i = 0; i < n; i++) {
		cin >> tem;
		arr.push_back(tem);
	}

	sort(arr.begin(), arr.end());

	int max;
	long long maxnum;

	max = 1;
	maxnum = arr[0];
	tem = arr[0];
	int count = 0;
	for (int i = 0; i < n; i++) {
		//cout << "값 확인 : " << i << "번째, arr[i] : " << arr[i] << "\n";
		if (tem != arr[i]) { //새로운 숫자
			//cout << "숫자 변경 : " << tem << " -> "<<arr[i]<<", count : " << count << ", max :"<<max<<"\n";
			if (count > max) { //최대 숫자
				max = count;
				//cout << "max 교체 : " << maxnum << " -> " << arr[i-1] << ", 횟수 : " << count << "\n";
				maxnum = arr[i - 1];
			}
			tem = arr[i]; //숫자 교체
			count = 1; //카운트 초기화
		}
		else count++;
	}
	if (count > max) {
		max = count;
		//cout << "max 교체 : " << maxnum << " -> " << arr[arr.size() - 1] << ", 횟수 : " << count << "\n";
		maxnum = arr[arr.size() - 1];
	}

	cout << maxnum << "\n";
}

int main()
{
	solution();
	return 0;
}
