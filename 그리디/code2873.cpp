#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1001
using namespace std;

int R, C;
int map[MAX][MAX];
int Happiness=0;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
bool visited[MAX][MAX];
vector<int> path;
int start = 0;


void showDirection(int num) {
	switch (num) { //상하좌우
	case 0: cout << "U";
		break;
	case 1:cout << "D";
		break;
	case 2:cout << "L";
		break;
	case 3:cout << "R";
		break;
	default: cout << "값 없음\n";
		break;
	}
	return;
}

bool DFS(int row, int col,int count) {
	visited[row][col] = true;
	if (row == R-1 && col == C-1) {
		if (Happiness < count) {
			Happiness = count;
			return true;
		}
		return false;
	}

	int nr, nc;
	//cout << "row : " << row << ", col : " << col << "일 때 !\n";
	for (int i = 0; i < 4; i++) {
		nr = row + dr[(start+i)%4];
		nc = col + dc[(start + i) % 4];

		if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
			if (!visited[nr][nc]) {
				if (DFS(nr, nc, count + map[nr][nc])) {
					path.push_back((start + i) % 4);
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	DFS(0, 0, map[0][0]);

	
	
	for (int i = path.size()-1; i >=0; i--) {
		showDirection(path[i]);
	}
	cout << "\n";
	
	cout << "이 때의 기쁨 수치 : " << Happiness << "\n";
	return 0;
}