#include <iostream>
#include <cstring>
#define MAX 26
using namespace std;

int n;
char graph[MAX][2];

void preorder(char root) { //���� ��ȸ
	cout << root; //�ٷ� ��带 ���

	for (int i = 0; i < 2; i++) {
		char next = graph[root - 'A'][i]; //�ε��� char Ÿ������ ��ȯ
		if (next != '.') //��尡 ������� ������
			preorder(next);
	}
	return;
}

void inorder(char root) { //���� ��ȸ
	char next = graph[root - 'A'][0];
	if (next != '.')
		inorder(next);

	cout << root;

	next = graph[root - 'A'][1];
	if (next != '.')
		inorder(next);
	return;
}

void postorder(char root) { //���� ��ȸ
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
		int r = node - 'A'; //����� ������ ���� (��尡 ������� �Էµ��� �����Ƿ�.)

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