#include <iostream>
#define MAX 1001
using namespace std;

int n, m;
bool graph[MAX][MAX];
bool visited[MAX];

void dfs(int start) {
	visited[start] = true;
	//cout << start << " ";

	for (int i = 0; i <= n; i++) {
		if (!visited[i] && graph[start][i]) {
			dfs(i);
		}
	}
	return;
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		graph[x][y] = true;
		graph[y][x] = true;
	}
	
	int count=0;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue; //이미 연결요소의 일부로 카운트됨
		else {
			//cout << "시작점 " << i << " case -------------------\n";
			dfs(i);
			//cout << "\n";
			count++;
		}
	}
	cout << count << "\n";

}