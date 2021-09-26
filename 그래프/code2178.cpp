#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int n, m;
int graph[MAX][MAX];
int dx[4] = { -1,1,0,0 };//상하좌우
int dy[4] = { 0,0,-1,1 };
bool visited[MAX][MAX];
int ret = 0;
queue<pair<pair<int, int>, int>> q; //<좌표값,cnt> 

void bfs(int x, int y, int cnt) {
	q.push(make_pair(make_pair(x, y), cnt));
	visited[x][y] = true;

	int nx, ny;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		cnt = q.front().second + 1;
		//cout << "(" << x << "," << y << "), cnt :: " << cnt << "\n";
		q.pop();

		if (x == n - 1 && y == m - 1) { //도착 판정
			if (ret == 0) ret = cnt;
			else if (ret > cnt) ret = cnt; //최솟값을 택함
			return;
		}

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) { //범위 내에 있고
				if (graph[nx][ny] == 1 && !visited[nx][ny]) { //이동할 수 있으며 아직 방문한 적 없다면
					q.push(make_pair(make_pair(nx, ny), cnt)); //좌표값과 cnt 값 페어로 push
					visited[nx][ny] = true;
				}
			}
		}

	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		char tem[MAX]; //문자열로 입력받기
		cin >> tem;
		for (int j = 0; j < m; j++) {
			graph[i][j] = tem[j] - '0'; //숫자로 graph 배열에 저장
		}
	}

	bfs(0, 0, 0);

	cout << ret << "\n";
	return 0;

}