#include <iostream>
#include <vector>
using namespace std;

vector<int> a_arr, b_arr;

int readToNum(vector<int> arr,int num) {
	int n=0;
	for (int i = arr.size()-1; i >=0; i--) {
		n *= 10;
		if (num == 6 && arr[i] == 5)	n += 6;
		else if (num == 5 && arr[i] == 6)	n += 5;
		else n += arr[i];	
	}

	return n;
}

int main() {
	int a, b;
	cin >> a >> b;

	for (int i = a; i > 0; i /= 10) {
		a_arr.push_back(i % 10);
	}
	for (int i = b; i > 0; i /= 10) {
		b_arr.push_back(i % 10);
	}
	
	cout << readToNum(a_arr, 5) + readToNum(b_arr, 5)<<" ";
	cout << readToNum(a_arr, 6) + readToNum(b_arr, 6) << "\n";

	return 0;
}