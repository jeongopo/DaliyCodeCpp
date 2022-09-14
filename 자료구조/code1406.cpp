#include <iostream>
#include <list>
using namespace std;

void PrintList(list<char> arr) {
	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << *it;
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list<char> arr;
	list<char>::iterator it; //커서의 오른쪽 노드를 가리키는 이터레이터

	string tem;
	cin >> tem;
	it = arr.end(); //처음엔 커서가 가장 끝에 있으므로 맨마지막 노드를 오른쪽에

	for (int i = 0; i < tem.length(); i++) {
		arr.push_back(tem[i]);
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		char command;
		cin >> command;
		switch (command) {
		case 'L': //커서 왼쪽으로
			if (it != arr.begin()) {
				it--;
			}
			break;
		case 'D': //커서 오른쪽으로
			if (it != arr.end()) {
				it++;
			}
			break;
		case 'B': //커서 왼쪽 문자 삭제
			if (it != arr.begin()) {
				it--; // 커서 기준 왼쪽에 있는 문자이므로, 하나 줄이기
				it = arr.erase(it);
			}
			break;
		case 'P': //커서 왼쪽에 추가
			char value;
			cin >> value;
			it = arr.insert(it, value); // 기존 노드를 오른쪽으로 밀도록 insert해주고
			it++; //원래 노드를 가리키게 하기

			break;
		default: break;
		}
		//PrintList(arr);
	}
	for (it = arr.begin(); it != arr.end(); it++) {
		cout << *it ;
	}

}
