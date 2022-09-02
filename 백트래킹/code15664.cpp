/*
20220901
백준 15664 : N과 M(10)
https://www.acmicpc.net/problem/15664
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int N, M;
map<vector<int>, bool> dic;

void BackTracking(vector<int> num, int start, vector<int> path) {
	if (path.size() == M) {
		if (dic[path] == false) {
			for (int i=0;i<path.size();i++) {
				cout << path[i] << " ";
			}
			cout << "\n";
			dic[path] = true;
		}
		return;
	}
	//cout << count << "\n";
	for (int i = start; i < N; i++) {
		vector<int> newPath = path;
		newPath.push_back(num[i]);
		BackTracking(num,i+1, newPath); // 숫자 i를 추가함
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<int> path;
	vector<int> number(N);
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
	sort(number.begin(), number.end());

	bool isvisited[10];
	for (int i = 0; i <= N; i++) {
		isvisited[i] = false;
	}
	BackTracking(number,0, path);
	return 0;
}
