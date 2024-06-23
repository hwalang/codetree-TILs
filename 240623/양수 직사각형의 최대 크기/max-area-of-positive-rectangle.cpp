#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetMaxSize(const vector<vector<int>>& grid, int N, int M)
{
    vector<vector<int>> dp(N, vector<int>(M, 0));
    int maxArea = 0;

    // 초기화 및 첫 번째 행, 첫 번째 열 처리
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (grid[y][x] > 0) {
                dp[y][x] = (x == 0) ? 1 : dp[y][x-1] + 1;
            } else {
                dp[y][x] = 0;
            }
        }
    }

    // 각 행에 대해 최대 크기 계산
    for (int x = 0; x < M; ++x) {
        for (int y1 = 0; y1 < N; ++y1) {
            if (dp[y1][x] == 0) continue;
            int width = dp[y1][x];
            for (int y2 = y1; y2 < N; ++y2) {
                width = min(width, dp[y2][x]);
                if (width == 0) break;
                int height = y2 - y1 + 1;
                maxArea = max(maxArea, width * height);
            }
        }
    }

    return maxArea;
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

    cout << GetMaxSize(grid, N, M) << endl;
    return 0;
}