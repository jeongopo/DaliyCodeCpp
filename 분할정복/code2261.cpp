#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 100001
using namespace std;

int mindistance;
int n;
vector<pair<int,int>> arr;
bool isvisited[MAX];

int distanceBetween(pair<int,int> a, pair<int,int> b) {
	return (pow((a.first - b.first), 2) + pow((a.second-b.second), 2));
}

bool compare(pair<int,int> a,pair<int,int> b) {
	if (a.first > b.first) return a > b;
	else a < b;
}

void findShortest(int idx) { //idx로부터 가장 가깝고, 가장 먼 길이로 시행
	isvisited[idx] = true;
	for (int i = 0; i < n; i++) {
		int tem = distanceBetween(arr[idx], arr[i]);
		if (i != idx &&!isvisited[i]&& tem < mindistance) {
			mindistance = tem;
			//cout << idx << " - " << i << " 최솟값 "<<mindistance<<"\n";
			findShortest(i);
		}
		else if (i != idx && !isvisited[i] && tem > mindistance) {
			//cout << idx << " - " << i << " 최댓값 " << maxdistance << "\n";
			findShortest(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr.push_back(make_pair(x, y));
	}

	sort(arr.begin(), arr.end(), compare);


	findShortest(0);

	cout << mindistance << "\n";

	return 0;
}