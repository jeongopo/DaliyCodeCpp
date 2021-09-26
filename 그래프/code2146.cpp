#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;

int n;
int graph[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0, -1,1 };

int min(int x, int y) { if (x > y) return y; else return x; }
void dfs(int x, int y, int num) {
	int nx, ny;

	graph[x][y] = num;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (graph[nx][ny] != 0 && !visited[nx][ny]) { //강이 아닌데, 아직 밟지 않았다면 같은 대륙임
				visited[nx][ny] = true;
				dfs(nx, ny, num);
			}
		}
	}
	return;
}

int bfs(int num) {
	queue<pair<int, int>> q;
	int x, y, nx, ny;
	int distance = 0; //대륙부터 시작하므로 초기값은 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == num) { //대륙으로부터의 거리를 구하기 위해, 대륙부터 q에 넣고 시작
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		int s = q.size();
		for (int t = 0; t < s; t++) { //대륙으로부터 거리가 같은 지점만큼만 q에서 꺼내기
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (graph[nx][ny] != 0 && graph[nx][ny] != num) { //새로운 대륙 도착
						//cout << "(" << nx << "," << ny << ") 리턴값 : " << distance << "\n";
						return distance;
					}
					if (graph[nx][ny] == 0 && !visited[nx][ny]) { //강
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		distance++; //한 칸 넘어가기
	}
	return 0;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) graph[i][j] = -1; //대륙들을 구분해주기 위해 처음엔 -1을 넣어주고 이후에 1,2,3 ... 의 값으로 채워줌
		}
	}

	int num = 1;
	for (int i = 0; i < n; i++) { //대륙 나누기
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == -1 && !visited[i][j]) {
				dfs(i, j, num);
				num++;
			}
		}
	}

	int ret = -1;
	for (int i = 1; i < num; i++) {
		memset(visited, false, sizeof(visited));
		if (ret == -1) ret = bfs(i); //가장 첫값은 그냥 넣기
		else ret = min(ret, bfs(i)); // 최솟값
	}

	cout << ret << "\n";
}