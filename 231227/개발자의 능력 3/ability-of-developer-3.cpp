#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

#define PERSON_NUM 6

int container[PERSON_NUM];
int ans = INT_MAX;

int GetDiff(int a, int b, int c) {

	int sum1 = container[a] + container[b] + container[c];
	int sum2 = 0;
	for (int i = 0; i < PERSON_NUM; ++i)
		sum2 += container[i];
	sum2 -= sum1;

	return abs(sum2 - sum1);
}

int main() {

	for (int i = 0; i < PERSON_NUM; ++i)
		cin >> container[i];

	// 1팀 정하기
	for (int i = 0; i < PERSON_NUM; ++i) {
		for (int j = i + 1; j < PERSON_NUM; ++j) {
			for (int k = j + 1; k < PERSON_NUM; ++k)
				ans = min(ans, GetDiff(i, j, k));	// 1, 2팀의 차이의 최소값 구하기
		}
	}

	cout << ans;

	return 0;
}