#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPositiveInGrid(const vector<vector<int>>& grid, int yy1, int xx1, int yy2, int xx2)
{
	for (int y1 = yy1; y1 < yy2; ++y1) {
		for (int x1 = xx1; x1 < xx2; ++x1) {
			if (grid[y1][x1] < 0) return false;
		}
	}

	return true;
}

int GetMaxSize(const vector<vector<int>>& grid, int N, int M)
{
	int maxSize = 0;

	// 직사각형 영역
	for (int y1 = 0; y1 < N; ++y1) {
		for (int x1 = 0; x1 < M; ++x1) {

			int size = 0;
			bool valid = true;

			for (int y2 = y1; y2 < N; ++y2) {
				for (int x2 = x1; x2 < M; ++x2) {
					if (IsPositiveInGrid(grid, y1, x1, y2, x2)) {
						size++;
					}
					else {
						size = 0;
						valid = false;
						break;
					}
				}

				if (!valid) {
					valid = true;
				}
				else {
					maxSize = max(maxSize, size);
				}
			}
		}
	}

	return maxSize;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> grid(N, vector<int>(M, 0));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> grid[y][x];
		}
	}

	cout << GetMaxSize(grid, N, M);
}