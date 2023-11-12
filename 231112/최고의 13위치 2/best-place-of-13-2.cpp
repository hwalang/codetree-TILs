#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 20

int N, ans;
int board[MAX_N][MAX_N];

bool IsWrap(int i, int j, int x, int y) {
	// 같은 줄에 있을 때만 겹치는지 판단하면 된다.
	if (i == x && j + 2 >= y) return true;
	return false;
}

bool InRange(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < N);
}

int main() {

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];
	}

	for (int i = 0; i < N; ++i) {		// 첫 번째 격자의 한 칸을 고정
		for (int j = 0; j < N; ++j) {
			if (!InRange(i, j + 2)) break;	// 격자 범위 밖이면 한 칸 아래로 이동

			// 첫 격자를 기준으로 두 번째 격자가 차지할 수 있는 모든 경우를 구함
			for (int x = i; x < N; ++x) {
				for (int y = 0; y < N; ++y) {
					int cnt = board[i][j] + board[i][j + 1] + board[i][j + 2];	// 첫 격자의 동전 수
					// 겹치면 continue;
					if (IsWrap(i, j, x, y)) continue;
					if (!InRange(x, y + 2)) break;
					cnt += (board[x][y] + board[x][y + 1] + board[x][y + 2]);
					ans = max(ans, cnt);
				}
			}
		}
	}

	cout << ans;

	return 0;
}