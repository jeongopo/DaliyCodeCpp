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
int longestNode = 0; //시작 노드로부터 가장 멀리 있는, 최대노드


void dfs(int node, int cost) {
	visited[node] = true;

	if (cost > maxcost) {
		maxcost = cost; //최댓값 업데이트
		longestNode = node; //최대노드 변경
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

			if (!visited[next]) { //다음 노드를 방문하지 않았다면
				q.push(make_pair(next, cost + nextcost));
				if (cost + nextcost > maxcost) {
					maxcost = cost + nextcost; //최댓값 업데이트
					longestNode = next; //최대노드 변경
					//cout << next << "에서 최대거리 : " << maxcost << "\n";
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
	bfs(longestNode, 0); //시작 노드로부터 가장 먼 노드에서 다시 BFS해봄

	cout << maxcost << "\n";

}