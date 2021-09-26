#include <iostream>
#include <cstring>
#define MAX 26
using namespace std;

int n;
char graph[MAX][2];

void preorder(char root) { //전위 순회
	cout << root; //바로 노드를 출력

	for (int i = 0; i < 2; i++) {
		char next = graph[root - 'A'][i]; //인덱스 char 타입으로 변환
		if (next != '.') //노드가 비어있지 않으면
			preorder(next);
	}
	return;
}

void inorder(char root) { //중위 순회
	char next = graph[root - 'A'][0];
	if (next != '.')
		inorder(next);

	cout << root;

	next = graph[root - 'A'][1];
	if (next != '.')
		inorder(next);
	return;
}

void postorder(char root) { //후위 순회
	for (int i = 0; i < 2; i++) {
		char next = graph[root - 'A'][i];
		if (next != '.')
			postorder(next);
	}
	cout << root;

	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char node;
		cin >> node;
		int r = node - 'A'; //노드의 영문자 순서 (노드가 순서대로 입력되지 않으므로.)

		for (int j = 0; j < 2; j++) {
			cin >> graph[r][j];
		}
	}

	preorder('A');
	cout << "\n";

	inorder('A');
	cout << "\n";

	postorder('A');
	cout << "\n";
}