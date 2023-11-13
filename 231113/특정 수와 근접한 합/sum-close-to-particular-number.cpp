#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

#define MAX_N 100

int S, N, ans = INT_MAX;
int nums[MAX_N];

int main() {

	cin >> N >> S;
	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	for (int i = 0; i < N; ++i) {	// 하나의 수를 지정
		for (int j = i + 1; j < N; ++j) {	// 두 번째 수를 지정
			// 지정한 두 수를 제외한 나머지 수들의 합을 구함
			int sum = 0;
			for (int k = 0; k < N; ++k) {
				if (k == i || k == j) continue;
				sum += nums[k];
			}
			
			ans = min(ans, abs(S - sum));
		}
	}

	cout << ans;

	return 0;
}