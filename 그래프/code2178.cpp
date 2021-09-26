#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int n, m;
int graph[MAX][MAX];
int dx[4] = { -1,1,0,0 };//�����¿�
int dy[4] = { 0,0,-1,1 };
bool visited[MAX][MAX];
int ret = 0;
queue<pair<pair<int, int>, int>> q; //<��ǥ��,cnt> 

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

		if (x == n - 1 && y == m - 1) { //���� ����
			if (ret == 0) ret = cnt;
			else if (ret > cnt) ret = cnt; //�ּڰ��� ����
			return;
		}

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) { //���� ���� �ְ�
				if (graph[nx][ny] == 1 && !visited[nx][ny]) { //�̵��� �� ������ ���� �湮�� �� ���ٸ�
					q.push(make_pair(make_pair(nx, ny), cnt)); //��ǥ���� cnt �� ���� push
					visited[nx][ny] = true;
				}
			}
		}

	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		char tem[MAX]; //���ڿ��� �Է¹ޱ�
		cin >> tem;
		for (int j = 0; j < m; j++) {
			graph[i][j] = tem[j] - '0'; //���ڷ� graph �迭�� ����
		}
	}

	bfs(0, 0, 0);

	cout << ret << "\n";
	return 0;

}