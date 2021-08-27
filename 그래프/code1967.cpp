#include <iostream>
#include <vector>;
#include <cstring>;
#define MAX 10001
using namespace std;

int n;
vector<pair<int, int>> tree[MAX]; //����ȣ, �������� �Ÿ� ����
bool visited[MAX];
int longestNode = 1; //���� �ָ� �ִ� ���
int longestDistance = 0; //���� �ָ� �ִ� �������� �Ÿ�

void DFS(int start,int cost) {
	//cout << start << "����\n";
	visited[start] = true;
	if (cost >= longestDistance) {
		longestNode = start;
		longestDistance = cost;
		//cout << "���� �� ��� : " << longestNode << ", �Ÿ� : " << longestDistance<<"\n";
	}

	for (int i = 0; i < tree[start].size(); i++) {
		int node = tree[start].at(i).first;
		int nodecost = tree[start].at(i).second;

		if (!visited[node]) {
			DFS(node,cost+nodecost);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int pnode,node,nodecost;
		cin >> pnode>>node>>nodecost;
		tree[pnode].push_back(make_pair(node, nodecost));
		tree[node].push_back(make_pair(pnode, nodecost));
	}

	DFS(1, 0);
	//cout << "1ȸ�� ���� �� ��� : " << longestNode << "\n";
	memset(visited, false, sizeof(visited));

	DFS(longestNode, 0);
	cout << longestDistance<<"\n";
	
	return 0;
}