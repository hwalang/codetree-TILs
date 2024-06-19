#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// block의 모든 상태를 나타내는 함수
vector<vector<pair<int, int>>> GetBlockShapes()
{
	vector<vector<pair<int, int>>> blockShapes;

	// L-block
	blockShapes.push_back({ {0, 0}, {1, 0}, {1, 1} });
	blockShapes.push_back({ {0, 0}, {0, 1}, {1, 0} });
	blockShapes.push_back({ {0, 0}, {0, 1}, {1, 1} });
	blockShapes.push_back({ {0, 0}, {1, 0}, {1, -1} });
	blockShapes.push_back({ {0, 0}, {0, -1}, {1, 0} });
	blockShapes.push_back({ {0, 0}, {-1, 0}, {-1, -1} });
	blockShapes.push_back({ {0, 0}, {0, -1}, {-1, 0} });
	blockShapes.push_back({ {0, 0}, {-1, 0}, {-1, 1} });

	// I-block
	blockShapes.push_back({ {0, 0}, {0, 1}, {0, 2} });
	blockShapes.push_back({ {0, 0}, {1, 0}, {2, 0} });

	return blockShapes;
}

int GetMaxSum(const vector<vector<int>>& grid, int row, int col, int N, int M)
{
	int maxSum = 0;
	vector<vector<pair<int, int>>> blockShapes = GetBlockShapes();

	// 하나의 block을 꺼낸다.
	for (const auto& block : blockShapes) {
		int curSum = 0;
		bool valid = true;

		// 꺼낸 block의 좌표값을 가져온다.
		for (const auto& inBlock : block) {
			int y = row + inBlock.first;
			int x = col + inBlock.second;
			if (y >= 0 && y < N && x >= 0 && x < M) {
				curSum += grid[y][x];
			}
			else {
				valid = false;
				break;
			}
		}

		if (valid) {
			maxSum = max(maxSum, curSum);
		}
	}

	return maxSum;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> grid(N, vector<int>(M));
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < M; ++col) {
			cin >> grid[row][col];
		}
	}

	int maxSum = 0;
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < M; ++col) {
			maxSum = max(maxSum, GetMaxSum(grid, row, col, N, M));
		}
	}


	cout << maxSum;
}