#include <iostream>
using namespace std;
#define ARRSIZE 1001

int max(int x, int y);


int main() {
	int n=0;
	
	int arr[ARRSIZE];
	
	int asc[ARRSIZE] = { 0, };
	int des[ARRSIZE] = { 0, };
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin>>arr[i];
		asc[i] =1;
		des[i]= 1;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			
			if (arr[i] > arr[j]) { //증가수열
				asc[i]=max(asc[i],asc[j]+1);
				//cout << "[증가] 시작점 " << i << ", 끝점" << j << "일 때의 최대길이 : " << asc[i] << "\n";
			}
		}
		
		for (int j = n-i+1; j <=n; j++) {
			if (arr[n-i+1] > arr[j]) {//감소수열
				des[n-i+1] = max(des[n-i+1],des[j] + 1);
				//cout << "[감소] 시작점 " << n-i+1 << ", 끝점 " << j << " 일 때의 최대길이 : " << des[n - i + 1] << "\n";
			}
		}
	}
	
	
	int maxval = 0;
	for (int i = 1; i <=n; i++) {
		if (i == 1) maxval = max(maxval, des[i]);
		else if (i == n) maxval = max(maxval, asc[i]);
		else {
			maxval = max(maxval, asc[i] + des[i] - 1);
		}
		//cout << i << "일 때 증가 : " << asc[i] << ", 감소 : " << des[i] << ", 최댓값 : " << maxval << "\n";
	}
	cout << maxval;
	
	return 0;
}

int max(int x, int y) {
	if (x >= y) return x;
	else return y;
}