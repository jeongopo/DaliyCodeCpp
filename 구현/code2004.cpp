#include <iostream>
using namespace std;

int min(long long x, long long  y) { //작은값 return
	if(x >= y) return y;
	else return x;
}

long long getfive(long long n) { //5의 개수
	long long r = 5;
	long long ret=0;
	while (r <= n) {
		ret += n / r;
		r = r * 5;
	}
	//cout << "[five] n :: " << n << ", ret :: " << ret << "\n";
	return ret;
}
long long gettwo(long long n) { //2의 개수
	long long r = 2;
	long long ret = 0;
	while (r <= n) {
		ret += n / r;
		r = r * 2;
	}
	//cout << "[two] n :: " << n << ", ret :: " << ret << "\n";
	return ret;
}

int main() {
	long long m, n;
	cin >> n;
	cin >> m;

	long long ret = 0;
	ret = min(getfive(n) - getfive(n - m)- getfive(m), gettwo(n) - gettwo(n - m) - gettwo(m)); 
    //5의 개수와 2의 개수 중 더 적은 값을 출력하기
	cout << ret << "\n";
	return 0;
}