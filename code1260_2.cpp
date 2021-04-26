#include <iostream>
#include <queue>
#define MAXSIZE 1001
using namespace std;

int n, m, v;
bool graph[MAXSIZE][MAXSIZE];
bool visit[MAXSIZE];
queue<int> dfsqueue;

void resetvisit() {
	for (int i = 0; i < MAXSIZE; i++) {
		visit[i] = false;
	}
}

void dfs(int p) {//DFS, 깊이우선탐색
	visit[p] = true;
	cout << p << " ";

	for (int i = 1; i <=n; i++) {
		if (graph[p][i]&&!visit[i]) { //연결되어 있고, 방문하지 않았다면 다음으로
			visit[i] = true; //방문 기록
			dfs(i); 
		}
	}
	return; //방문할 노드가 없다면 리턴
}

void bfs(int p) {//BFS, 너비우선탐색
	dfsqueue.push(p); //현재 정점을 실행하기 위해 push해줌
	visit[p] = true;
	cout << p << " ";

	while (!dfsqueue.empty()) {
		int tem = dfsqueue.front();
		dfsqueue.pop();
		for (int i = 1; i <= n; i++) {
			if (graph[tem][i] && !visit[i]) { //연결되어 있고, 방문하지 않았다면 다음으로
				visit[i] = true; //방문 기록
				dfsqueue.push(i); //큐에 정점 기록하기
				cout << i << " ";
			}
		}
	}
	return;
}

int main() {
	
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		graph[x][y] = true;
		graph[y][x] = true;
	}

	resetvisit();
	dfs(v);
	cout << "\n";

	resetvisit();
	bfs(v);
	cout << "\n";
	return 0;
}