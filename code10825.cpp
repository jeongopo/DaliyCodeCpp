#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXSIZE 100001;

class Student {
public:
	string name;
	int a;
	int b;
	int c;
	Student(string name, int a, int b, int c) {
		this->name = name;
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

bool compare(Student x, Student y) {
	if (x.a == y.a) {
		if (x.b == y.b) {
			if (x.c == y.c) {
				return x.name < y.name;
			}
			else return x.c > y.c;
		}
		else return x.b < y.b;
	}else  return x.a > y.a;
}

void solution() {
	vector<Student> arr;

	int n;
	cin >> n;
	
	string name;
	int a, b, c;

	for (int i = 0; i < n; i++) {
		cin >> name;
		cin >> a;
		cin >> b;
		cin >> c;
		arr.push_back(Student(name, a, b, c));
	}

	stable_sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i].name << "\n";
	}

}

int main() {
	solution();
}

