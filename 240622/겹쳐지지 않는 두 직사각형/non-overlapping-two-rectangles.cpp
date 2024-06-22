#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 그리드를 읽는 함수
void readGrid(int &n, int &m, vector<vector<int>> &grid) {
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
}

// Prefix Sum을 계산하는 함수
void computePrefixSums(const vector<vector<int>> &grid, vector<vector<int>> &prefix) {
    int n = grid.size();
    int m = grid[0].size();
    prefix.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
}

// 서브 직사각형의 합을 구하는 함수
int getSum(const vector<vector<int>> &prefix, int r1, int c1, int r2, int c2) {
    return prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
}

// 최대 합을 계산하는 함수
int findMaxSum(const vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> prefix;
    computePrefixSums(grid, prefix);
    
    int max_sum = INT_MIN;

    for (int r1 = 0; r1 < n; ++r1) {
        for (int c1 = 0; c1 < m; ++c1) {
            for (int r2 = r1; r2 < n; ++r2) {
                for (int c2 = c1; c2 < m; ++c2) {
                    int sum1 = getSum(prefix, r1, c1, r2, c2);

                    for (int r3 = 0; r3 < n; ++r3) {
                        for (int c3 = 0; c3 < m; ++c3) {
                            for (int r4 = r3; r4 < n; ++r4) {
                                for (int c4 = c3; c4 < m; ++c4) {
                                    if (r3 > r2 || r4 < r1 || c3 > c2 || c4 < c1) {
                                        int sum2 = getSum(prefix, r3, c3, r4, c4);
                                        max_sum = max(max_sum, sum1 + sum2);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return max_sum;
}

int main() {
    int n, m;
    vector<vector<int>> grid;
    readGrid(n, m, grid);
    cout << findMaxSum(grid) << endl;
    return 0;
}