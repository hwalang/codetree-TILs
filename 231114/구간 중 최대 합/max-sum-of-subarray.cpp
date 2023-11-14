#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100

int N, K, ans;
int nums[MAX_N];

int main() {

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	for (int i = 0; i <= N - K; ++i) {
		int sum = 0;
		for (int j = i; j < i + K; ++j) {
			sum += nums[j];
		}

		ans = max(ans, sum);
	}

	cout << ans;

	return 0;
}