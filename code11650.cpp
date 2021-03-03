#include <iostream>
using namespace std;
#define MAXSIZE 100001
#include <algorithm>;
#include <vector>;

class Location {
public:
	int x;
	int y;
	Location(int x, int y) :x(x), y(y) {}
};

bool compare(Location a, Location b) {
	if (a.x == b.x) return a.y < b.y; //정렬해야하면false
	else return a.x < b.x;
}

void solution() {
	int n,x,y;
	cin >> n;

	vector<Location> arr;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cin >> y;
		arr.push_back(Location(x,y));
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i].x << " " << arr[i].y << "\n";
	}

}

int main() {
	solution();
	return 0;
}