#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int* n_arr;
	int* m_arr;
	int* answer;

	cin >> n >> m;
	n_arr = new int[n];
	m_arr = new int[m];
	answer = new int[n + m];

	for (int i = 0; i < n; i++) {
		cin >> n_arr[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> m_arr[i];
	}

	int n_index=0, m_index=0;
	int index=0;
	while (n_index < n && m_index < m) {
		if (n_arr[n_index] < m_arr[m_index]) {
			answer[index++] = n_arr[n_index++];
		}
		else answer[index++] = m_arr[m_index++];
	}

	while(n_index<n) answer[index++] = n_arr[n_index++];
	while(m_index<m) answer[index++] = m_arr[m_index++];

	for (int i = 0; i < n + m; i++) cout << answer[i] << " ";
	cout << "\n";

	return 0;
}