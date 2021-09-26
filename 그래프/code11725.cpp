#include <iostream>
#include <cstring>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> arr[MAX];
bool visited[MAX];
int parent[MAX];

void dfs(int start) {
	visited[start] = true;
	for (int i = 0; i < arr[start].size(); i++) {//모든 자식노드에 대해서 진행
		if (!visited[arr[start].at(i)]) { //방문하지 않은 노드라면
			//cout << start << " -> " << arr[start].at(i) << "\n";
			parent[arr[start].at(i)] = start; //부모 노드를 기록함
			dfs(arr[start].at(i)); //자식을 찾아서 내려감
			visited[arr[start].at(i)] = true;
		}
	}
}

int main() {
	int n;
	cin >> n;

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y); //노드 연결 정보 기록
		arr[y].push_back(x);
	}

	dfs(1); //루트 노드부터 아래로 진행

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}

}