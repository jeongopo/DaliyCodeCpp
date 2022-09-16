
/*
220916
백준 2811 : 상범이의 우울
https://www.acmicpc.net/problem/2811
*/

#include <iostream>
#include <vector>
using namespace std;


void AnswerCount(vector<bool> check) {
	int answer=0;
	for (int i = 0; i < check.size(); i++) {
		if (check[i])	answer++;
	}
	cout << answer << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> happy(n);
	vector<bool> check(n);

	for (int i = 0; i < n; i++) {
		cin >> happy[i];
		check[i] = false;
	}

	int blueMaxLength = 0;
	int answer = 0;
	int count = 0;
	int startIndex = n+1;
	
	for (int i = 0; i < n; i++) {
		if (happy[i] >= 0 || i == n - 1) {
			if (i == n - 1 && happy[i] < 0) { // 마지막 케이스
				count++;
				startIndex = min(startIndex, i);
			}

			if (count > 0) { // 우울 기간이 끝났을 때
				if (blueMaxLength <= count) { //최댓값 갱신
					blueMaxLength = count;
				}

				for (int j = startIndex - 1; j >= max(0, startIndex - count * 2); j--) {
					check[j] = true;
				}
				
				//cout << i - 1 << "번째 우울 끝, " << count << "\n";
				//cout << startIndex - 1 << "~" << max(0, startIndex - count * 2) << "까지 true\n";
				//cout << "\n";
				
				//AnswerCount(check);

			}
			startIndex = n + 1;
			count = 0;
		}
		else if (happy[i] < 0) {
			startIndex = min(startIndex, i);
			count++;
		}

	}

	for (int i = 0; i < n; i++) {
		if (check[i])	answer++;
	}

	//최장 기간이 여러개라면 가장 많은 꽃을 더할 수 있는 날을 찾기
	count = 0;
	int maxAdd = 0;
	int index = n+1;
	int temcount = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || happy[i]>=0) {
			if (count == blueMaxLength) {
				for (int j = index - 1; j >= max(0, index - count * 3); j--) {
					if (!check[j])	temcount++;
				}
				maxAdd = max(maxAdd, temcount);
				temcount = 0;
			}
			index = n + 1;
			count = 0;
		}else if (happy[i]<0) {
			index = min(index, i);
			count++;
		}
	}

	//cout << maxAdd << " 더하기\n";
	answer += maxAdd;

	//cout << "\n\n";
	cout << answer << "\n";
	
	return 0;
}
