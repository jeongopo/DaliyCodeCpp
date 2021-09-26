#include <iostream>
#include <cstring>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> arr[MAX];
bool visited[MAX];
int parent[MAX];

void dfs(int start) {
	visited[start] = true;
	for (int i = 0; i < arr[start].size(); i++) {//��� �ڽĳ�忡 ���ؼ� ����
		if (!visited[arr[start].at(i)]) { //�湮���� ���� �����
			//cout << start << " -> " << arr[start].at(i) << "\n";
			parent[arr[start].at(i)] = start; //�θ� ��带 �����
			dfs(arr[start].at(i)); //�ڽ��� ã�Ƽ� ������
			visited[arr[start].at(i)] = true;
		}
	}
}

int main() {
	int n;
	cin >> n;

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y); //��� ���� ���� ���
		arr[y].push_back(x);
	}

	dfs(1); //��Ʈ ������ �Ʒ��� ����

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}

}