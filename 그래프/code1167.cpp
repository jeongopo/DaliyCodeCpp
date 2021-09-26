#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

vector<pair<int, int>> tree[MAX];
int v;
queue<pair<int, int>> q;
int maxcost = 0;
bool visited[MAX];
int longestNode = 0; //���� ���κ��� ���� �ָ� �ִ�, �ִ���


void dfs(int node, int cost) {
	visited[node] = true;

	if (cost > maxcost) {
		maxcost = cost; //�ִ� ������Ʈ
		longestNode = node; //�ִ��� ����
	}

	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node].at(i).first;
		int nextcost = tree[node].at(i).second;

		if (!visited[next]) {
			dfs(next, cost + nextcost);
		}
	}
}


void bfs(int node, int cost) {

	q.push(make_pair(node, cost));

	while (!q.empty()) {
		node = q.front().first;
		cost = q.front().second;
		//cout << "node : " << node << ", cost : " << cost << "\n";
		visited[node] = true;
		q.pop();

		for (int i = 0; i < tree[node].size(); i++) {
			int next = tree[node].at(i).first;
			int nextcost = tree[node].at(i).second;

			if (!visited[next]) { //���� ��带 �湮���� �ʾҴٸ�
				q.push(make_pair(next, cost + nextcost));
				if (cost + nextcost > maxcost) {
					maxcost = cost + nextcost; //�ִ� ������Ʈ
					longestNode = next; //�ִ��� ����
					//cout << next << "���� �ִ�Ÿ� : " << maxcost << "\n";
				}
			}
		}
	}
}
int main() {
	cin >> v;

	for (int i = 0; i < v; i++) {
		int x, y, cost;
		cin >> x;

		cin >> y;
		while (y != -1) {
			cin >> cost;
			tree[x].push_back(make_pair(y, cost));
			tree[x].push_back(make_pair(x, cost));
			cin >> y;
		}
	}


	bfs(1, 0);
	memset(visited, false, sizeof(visited));
	bfs(longestNode, 0); //���� ���κ��� ���� �� ��忡�� �ٽ� BFS�غ�

	cout << maxcost << "\n";

}