#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> cities;
int map[11][11];
int n;
int mincost=0;

void TPS() {
	int x, y;
	int cost = 0;
	for (int i = 0; i < cities.size()-1; i++) {
		x = cities[i];
		y = cities[i + 1];
		if (map[x][y] == 0)	return;
		else cost += map[x][y];
	}

	if (map[cities[cities.size() - 1]][cities[0]] != 0)	cost += map[cities[cities.size() - 1]][cities[0]];
	else return;

	mincost = min(mincost, cost);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			mincost += map[i][j]; //¡÷¿«?
		}
	}

	for (int i = 0; i < n; i++) {
		cities.push_back(i);
	}

	do {
		TPS();
	} while (next_permutation(cities.begin(), cities.end()));

	cout << mincost << "\n";
	return 0;
}