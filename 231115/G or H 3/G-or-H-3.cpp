#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_L 10000

int N, K, ans, max_idx;
int loc[MAX_L + 1];

int main() {

	cin >> N >> K;
	int cur_idx; char alpha;
	for (int i = 0; i < N; ++i) {
		cin >> cur_idx >> alpha;
		if (alpha == 'G')
			loc[cur_idx] = 1;
		else
			loc[cur_idx] = 2;
		max_idx = max(max_idx, cur_idx);
	}

	// 구간 합 구하기
	K++;
	for (int i = 1; i <= max_idx + K - 1; ++i) {
		int sum = 0;
		for (int j = i; j < i + K; ++j)
			sum += loc[j];
		ans = max(ans, sum);
	}

	cout << ans;

	return 0;
}