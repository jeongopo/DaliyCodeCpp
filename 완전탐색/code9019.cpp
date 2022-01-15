#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

bool visited[10001];
pair<int,int> BT[10001];
char outDSLR[5] = {'0', 'D','S','L','R' };
int a,b;
vector<char> path;

int moveLeft(int val) {
	int num[4];

	for (int i = 3; i >=0; i--) {
		num[i] = val % 10;
		val /= 10;
	}
	for (int i = 0; i < 3; i++) {
		swap(num[i], num[i + 1]);
	}

	int ret = num[0];
	for (int i = 1; i < 4; i++) {
		ret *= 10;
		ret += num[i];
	}
	//cout << ret << "\n";
	return ret;
}

int moveRight(int val) {
	int num[4];

	for (int i = 3; i >= 0; i--) {
		num[i] = val % 10;
		val /= 10;
	}
	for (int i = 3; i >0; i--) {
		swap(num[i], num[i - 1]);
	}

	int ret = num[0];
	for (int i = 1; i < 4; i++) {
		ret *= 10;
		ret += num[i];
	}
	//cout << ret << "\n";
	return ret;
}


void BFS(int start) {
	queue<int> q;

	q.push(start);
	BT[start]=make_pair(start,0);
	visited[start] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == b) {
			return;
		}
		int dslr[5];
		dslr[1] = (now * 2) % 10000;

		dslr[2] =now- 1;
		if (dslr[2] < 0)	dslr[2] = 9999;
		dslr[3] = moveLeft(now);
		dslr[4] = moveRight(now);

		for (int i = 1; i < 5; i++) {
			if (!visited[dslr[i]]) {
				visited[dslr[i]]=true;
				BT[dslr[i]]=make_pair(now,i);
				q.push(dslr[i]);
			}
		}
		
	}
}

void backtracking(int start) {
	if (start == a)	return;

	path.push_back(outDSLR[BT[start].second]);
	backtracking(BT[start].first);

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> a>>b;

		memset(visited, false, sizeof(visited));
		path.clear();
		BFS(a);
		backtracking(b);

		for (int i = path.size() - 1; i >= 0; i--) {
			cout << path[i];
		}
		cout << "\n";
	}

	return 0;
}