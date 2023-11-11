#include <iostream>
using namespace std;

#define MAX_N 19
#define MAX_D 4

int board[MAX_N][MAX_N];
int ans, middle_x, middle_y;
bool isWhiteWin, isBlackWin;
int dx[MAX_D] = { 1, 1 };	// 오른쪽 아래 대각선, 왼쪽 아래 대각선
int dy[MAX_D] = { 1, -1 };

bool InRange(int x, int y) {
	return (x >= 0 && y >= 0 && x < MAX_N && y < MAX_N);
}

bool IsFiveRightDiagonal(int num) {

	int dir = 0;
	for (int i = 0; i < MAX_N; ++i) {
		for (int j = 0; j < MAX_N; ++j) {
			if (board[i][j] != num) continue;	// num이 아닌 경우

			// cnt = 1부터 시작
			int cnt = 1;
			int nx = i;
			int ny = j;
			for (; cnt < 5; ++cnt) {		// 연속된 5줄을 찾는다.
				nx += dx[dir];
				ny += dy[dir];
				if (!InRange(nx, ny) || board[ny][ny] != num) break;	// 범위 밖 또는 num이 아닌 경우
			}

			if (cnt == 5) {		// 5줄인 경우
				ans = num;
				middle_x = (i + 1) + 2;
				middle_y = (j + 1) + 2;
				return true;
			}
		}
	}

	return false;
}

bool IsFiveLeftDiagonal(int num) {

	int dir = 1;
	for (int i = 0; i < MAX_N; ++i) {
		for (int j = 0; j < MAX_N; ++j) {
			if (board[i][j] != num) continue;	// num이 아닌 경우

			// cnt = 1부터 시작
			int cnt = 1;
			int nx = i;
			int ny = j;
			for (; cnt < 5; ++cnt) {		// 연속된 5줄을 찾는다.
				nx += dx[dir];
				ny += dy[dir];
				if (!InRange(nx, ny) || board[nx][ny] != num) 
					break;	// 범위 밖 또는 num이 아닌 경우
			}

			if (cnt == 5) {		// 5줄인 경우
				ans = num;
				middle_x = (i + 1) + 2;
				middle_y = (j + 1) - 2;
				return true;
			}
		}
	}

	return false;
}

bool IsFiveHeight(int num) {

	for (int i = 0; i < MAX_N; ++i) {
		int cnt = 0;		// 줄이 바뀔 때마다 cnt는 초기화
		for (int j = 0; j < MAX_N; ++j) {
			if (board[j][i] != num) {	// 이어지지 않는 경우
				cnt = 0;
				continue;
			}

			if (board[j][i] == num)		// num 인 경우
				cnt++;

			if (cnt == 5) {				// 5줄을 만족하는 경우
				ans = num;
				middle_x = (j + 1) - 2;		// 1번부터 시작
				middle_y = (i + 1);
				return true;
			}
		}
	}

	return false;
}

bool IsFiveWidth(int num) {
	
	for (int i = 0; i < MAX_N; ++i) {
		int cnt = 0;		// 줄이 바뀔 때마다 cnt는 초기화
		for (int j = 0; j < MAX_N; ++j) {
			if (board[i][j] != num) {	// 이어지지 않는 경우
				cnt = 0;
				continue;
			}

			if (board[i][j] == num)		// num 인 경우
				cnt++;

			if (cnt == 5) {				// 5줄을 만족하는 경우
				ans = num;
				middle_x = (i + 1);		// 1번부터 시작
				middle_y = (j + 1) - 2;		
				return true;
			}
		}
	}

	return false;
}

bool WinWhite() {

	int white = 2;
	if (IsFiveWidth(white)) {	// 5줄 판단: 가로
		return true;
	}
	else if (IsFiveHeight(white)) {	// 5줄 판단: 세로
		return true;
	}
	else if (IsFiveLeftDiagonal(white)) {	// 5줄 판단: 왼쪽 아래 대각선
		return true;
	}
	else if (IsFiveRightDiagonal(white)) {	// 5줄 판단: 오른쪽 아래 대각선
		return true;
	}

	return false;
}

bool WinBlack() {

	int black = 1;
	if (IsFiveWidth(black)) {	// 5줄 판단: 가로
		return true;
	}
	else if (IsFiveHeight(black)) {	// 5줄 판단: 세로
		return true;
	}
	else if (IsFiveLeftDiagonal(black)) {	// 5줄 판단: 왼쪽 아래 대각선
		return true;
	}
	else if (IsFiveRightDiagonal(black)) {	// 5줄 판단: 오른쪽 아래 대각선
		return true;
	}

	return false;
}

void Solution() {

	if (WinWhite()) {	// 1번이 이긴 경우
		cout << ans << endl;
		cout << middle_x << " " << middle_y << endl;
		return;
	}
	else if (WinBlack()) {	// 2번이 이긴 경우
		cout << ans << endl;
		cout << middle_x << " " << middle_y << endl;
		return;
	}
	
	// 승부가 나지 않은 경우
	cout << ans;
}

int main() {

	for (int i = 0; i < MAX_N; ++i) {
		for (int j = 0; j < MAX_N; ++j)
			cin >> board[i][j];
	}

	Solution();

	return 0;
}