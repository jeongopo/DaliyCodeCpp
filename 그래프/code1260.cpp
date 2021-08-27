#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
class Node {
public:
	vector<int> arr;
};

void connect(Node* graph, int x, int y) {
	graph[x].arr.push_back(y);
	graph[y].arr.push_back(x);
	cout << x << " - " << y << " 간선 연결";
}



void printGraph(Node* graph,int n) {
	for (int i = 1; i <= n; i++) {
		cout << i << " :: ";
		for (int j = 0; j < graph[i].arr.size(); j++) {
			cout << graph[i].arr[j] << " ";
		}
		cout << "\n";
	}
}

bool bfs(Node* graph, stack<int>* path, int n) {

}

int main() {
	int n, m, v;
	cin >> n >> m >> v;
	Node* graph;
	graph = new Node[n + 1];
	stack<int> path;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x;
		cin >> y;

		connect(graph, x, y);
	}
	for (int i = 1; i <=n; i++) {
		sort(graph[i].arr.begin(), graph[i].arr.end());
	}

	int p = graph[v].arr[0];
	bool *visit;
	visit = new bool[n + 1];

	//DFS
	while (1) {
		if (p == v) break;
		else {
			for (int i = 0; i < graph[p].arr.size(); i++) {
				if (!visit[graph[p].arr[i]]) {
					visit[graph[p].arr[i]] = true;
					p = graph[p].arr[i];
					cout << p << " ";
					break;
				}
			}
		}
	}

	//printGraph(graph,n);

	return 0;
}