#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX_N = 20;
int grid[MAX_N][MAX_N];

// grid 밖으로 나가지 않으면 true
bool InRanged(int x, int y, int N)
{
	return y >= 0 && y < N && x >= 0 && x < N;
}

// 현재 좌표에서 만들 수 있는 가장 큰 직사각형을 만든 뒤 최대합을 반환한다.
int GetSumOfRhombus(int x, int y, int N)
{
	// 1, 2, 3, 4번 이동 방향
	pair<int, int> dir[] = { {-1, 1}, {-1, -1}, {1, -1}, {1, 1} };	

	int sum = 0;

	// grid 밖을 나가지 않는 범위 내에서 한 방향을 계속 전진하며서 합을 구함
	int curX = x;
	int curY = y;
	for (int d = 0; d < 4; ++d) {

		while (true) {
			int nextX = curX + dir[d].first;
			int nextY = curY + dir[d].second;
			
			//cout << "d: " << d << " first, second: " << dir[d].first << " | " << dir[d].second << endl;

			if (!InRanged(nextX, nextY, N)) {		// 최상, 최좌, 최우는 이미 막혔기에 sum 값이 한 번은 무조건 갱신
				//cout << "( " << curX << ", " << curY << " ): " << grid[curX][curY]  << endl;
				break;
			}

			sum += grid[nextX][nextY];
			//cout << "sum: " << sum << endl;
			curX = nextX;
			curY = nextY;
		}
	}

	return sum;
}

int main()
{
	int N;
	cin >> N;

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			cin >> grid[x][y];
		}
	}

	int maxSum = 0;

	// 최상단 + 그 밑, 최좌단, 최우단은 제외
	for (int x = 2; x < N; ++x) {
		for (int y = 1; y < N - 1; ++y) {
			maxSum = max(maxSum, GetSumOfRhombus(x, y, N));
		}
	}

	cout << maxSum;
}