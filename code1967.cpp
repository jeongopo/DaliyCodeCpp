#include <iostream>
#include <vector>;
#include <cstring>;
#define MAX 10001
using namespace std;

int n;
vector<pair<int, int>> tree[MAX]; //노드번호, 노드까지의 거리 저장
bool visited[MAX];
int longestNode = 1; //가장 멀리 있는 노드
int longestDistance = 0; //가장 멀리 있는 노드까지의 거리

void DFS(int start,int cost) {
	//cout << start << "입장\n";
	visited[start] = true;
	if (cost >= longestDistance) {
		longestNode = start;
		longestDistance = cost;
		//cout << "가장 먼 노드 : " << longestNode << ", 거리 : " << longestDistance<<"\n";
	}

	for (int i = 0; i < tree[start].size(); i++) {
		int node = tree[start].at(i).first;
		int nodecost = tree[start].at(i).second;

		if (!visited[node]) {
			DFS(node,cost+nodecost);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int pnode,node,nodecost;
		cin >> pnode>>node>>nodecost;
		tree[pnode].push_back(make_pair(node, nodecost));
		tree[node].push_back(make_pair(pnode, nodecost));
	}

	DFS(1, 0);
	//cout << "1회차 가장 먼 노드 : " << longestNode << "\n";
	memset(visited, false, sizeof(visited));

	DFS(longestNode, 0);
	cout << longestDistance<<"\n";
	
	return 0;
}