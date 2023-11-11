#include <iostream>
#include <string>
using namespace std;

#define MAX_S 50
#define MAX_D 8

int N, M, ans;
string input;
char arr[MAX_S][MAX_S];
int dx[MAX_D] = { -1, -1, 0, 1, 1, 1, 0, -1 }; // 맨 위에서 시작
int dy[MAX_D] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool InRange(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < M);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		for (int j = 0; j < M; ++j)
			arr[i][j] = input[j];
	}

	// 하나의 칸을 선택
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] != 'L') continue;

			// 'L' 문자를 찾은 경우
			int cur_x = i;
			int cur_y = j;
			// 8 방향을 살펴보면서 'EE'을 만족하는지 찾는다.
			for (int d = 0; d < MAX_D; ++d) {
				int nx = cur_x + dx[d];
				int ny = cur_y + dy[d];

				// 한 방향으로 이동하면서 탐색한다.
				int k = 0;
				for (; k < 2; ++k) {
					// 격자 밖 또는 'E'가 아닌 경우 다음 방향으로 넘긴다.
					if (!InRange(nx, ny) || arr[nx][ny] != 'E') break;
					nx += dx[d];
					ny += dy[d];
				}

				// 'EE'를 찾은 경우
				if (k == 2)
					ans++;
			}
		}
	}

	cout << ans;

	return 0;
}