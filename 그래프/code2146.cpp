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
			if (graph[nx][ny] != 0 && !visited[nx][ny]) { //���� �ƴѵ�, ���� ���� �ʾҴٸ� ���� �����
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
	int distance = 0; //������� �����ϹǷ� �ʱⰪ�� 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == num) { //������κ����� �Ÿ��� ���ϱ� ����, ������� q�� �ְ� ����
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		int s = q.size();
		for (int t = 0; t < s; t++) { //������κ��� �Ÿ��� ���� ������ŭ�� q���� ������
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (graph[nx][ny] != 0 && graph[nx][ny] != num) { //���ο� ��� ����
						//cout << "(" << nx << "," << ny << ") ���ϰ� : " << distance << "\n";
						return distance;
					}
					if (graph[nx][ny] == 0 && !visited[nx][ny]) { //��
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		distance++; //�� ĭ �Ѿ��
	}
	return 0;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) graph[i][j] = -1; //������� �������ֱ� ���� ó���� -1�� �־��ְ� ���Ŀ� 1,2,3 ... �� ������ ä����
		}
	}

	int num = 1;
	for (int i = 0; i < n; i++) { //��� ������
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
		if (ret == -1) ret = bfs(i); //���� ù���� �׳� �ֱ�
		else ret = min(ret, bfs(i)); // �ּڰ�
	}

	cout << ret << "\n";
}