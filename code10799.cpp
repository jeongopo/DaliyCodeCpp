#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void solution() {
	string tem;
	stack<char> arr1;
	stack<int> arr2;
	vector<int> ray;

	cin >> tem;
	for (int i = 0; i < tem.length(); i++) {
		arr1.push(tem[i]);
	}

	int ret = 0;
	int index=1;
	while(!arr1.empty()) {
		if (arr1.top() == ')') {
			arr1.pop();
			if (arr1.top() == '(') {
				ray.push_back(index);
				//cout << "레이저 추가 : " << index << ", 누적 레이저 개수 :" << ray.size() << "\n";
				arr1.pop();
				index++;
			}
			else if (arr1.top() == ')') {
				arr2.push(index);
				index++;
			}
		}
		else if (arr1.top() == '(') {
			arr1.pop();
			int start = arr2.top();
			arr2.pop();
			int temsize = 1;
			for (int j = 0; j < ray.size(); j++) {
				if (start > ray[j]) {}
				else if (index < ray[j]) {}
				else temsize++;
			}
			//cout << "막대기 : " << start << " ~ " << index << ", "<<temsize<<"개로 절단됨\n";
			ret += temsize;
			index++;
		}
	}
	cout << ret << '\n';

}

int main() {

	solution();
	return 0;
}