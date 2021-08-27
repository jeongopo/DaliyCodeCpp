#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAXSIZE 100001


class Customer {
public:
	string name;
	int age;
	Customer(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

bool compare(const Customer &a, const Customer &b) {
	return a.age < b.age;//정렬해야하면 false
}

void solution() {
	int n, age;
	string name;
	cin >> n;

	vector<Customer> arr;
	for (int i = 0; i < n; i++) {
		cin >> age;
		cin >> name;
		arr.push_back(Customer(name, age));
	}

	stable_sort(arr.begin(), arr.end(), compare); //같은 경우 때문에 stable

	for (int i = 0; i < n; i++) {
		cout << arr[i].age << " " << arr[i].name << "\n";
	}

}

int main() {
	solution();
	return 0;
}