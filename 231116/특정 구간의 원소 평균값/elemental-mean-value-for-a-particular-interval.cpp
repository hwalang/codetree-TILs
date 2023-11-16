#include <iostream>
using namespace std;

#define MAX_N 100

int N, ans;
int nums[MAX_N];

int main() {

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	ans = N;	// 하나의 구간은 평균과 원소 값이 같다.

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			// 평균 구하기
			int sum = 0;
			double avg = 0;
			for (int k = i; k <= j; ++k)
				sum += nums[k];
			avg = (double)sum / (j - i + 1);

			// 구간 내에 평균과 일치하는 원소 찾기
			for (int k = i; k <= j; ++k) {
				if (avg == nums[k]) {
					ans++;
					break;
				}
			}
		}
	}

	cout << ans;

	return 0;
}