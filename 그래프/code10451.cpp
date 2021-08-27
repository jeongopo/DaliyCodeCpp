#include <iostream>
#define MAX 1001
using namespace std;

int* graph;
int n;
bool visited[MAX];

void init() {
	for (int i = 0; i <= n; i++) {
		visited[i] = false; //visited 초기화
	}
}
void bfs(int start) {
	visited[start] = true;
	//cout << start << "\n";
	
	if (!visited[graph[start]]) { //1개의 정점만 이어져 있으므로 반복문은 필요 x
		bfs(graph[start]);
	}

	return;
}

int main() {
	int t;
	cin >> t;

	for (int j = 0; j < t; j++) {
		cin >> n;
		init();
		graph = new int[n + 1]; 
		for (int i = 1; i <= n; i++) {
			int tem;
			cin >> tem;
			graph[i] = tem;
		}

		int ret = 0;
		for (int i = 1; i <= n; i++) {
			//cout << i << "번째 실행=============\n";
			if (visited[i] == false) { //방문하지 않았다면 새로운 사이클
				bfs(i);
				ret++;
			}
		}
		cout << ret << "\n";
	}
	return 0;
}