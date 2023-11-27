#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100

int N, K, ans;				// K: 구간 크기
int barket[MAX_N + 1];	// 바구니 위치: 0 ~ 100

int main() {

	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		// 바구니 위치와 사탕 개수를 입력 받는다.
		int cnt, loc;
		cin >> cnt >> loc;
		barket[loc] = cnt;
	}
	
	// 중심점을 잡는다.
	for (int i = 0; i <= MAX_N; ++i) {
		// i점을 기준으로 + - K 만큼 탐색하면서 사탕 수를 센다. 
		// i가 0이면 k까지 셀 수 있다.
		int candyCnt = barket[i];
		for (int k = i + 1; k <= i + K; ++k) {
			if (k > MAX_N) break;
			candyCnt += barket[k];
		}

		for (int k = i - 1; k >= i - K; --k) {
			if (k < 0) break;
			candyCnt += barket[k];
		}

		ans = max(ans, candyCnt);
	}
	
	cout << ans;

	return 0;
}