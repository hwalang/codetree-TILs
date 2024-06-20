#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 20;

int mineArea[MAX_N][MAX_N];

int GetCost(int K)
{
	return K * K + (K + 1) * (K + 1);
}

// 현재 좌표에서 k를 증가시키면서 모든 gold를 포함했을때까지 탐색한다.
int GetNumOfGold(int y, int x, int N, int M)
{
	int maxGold = 0;
	for (int k = 0; k <= N; ++k) {
		int goldCnt = 0;
		// 마름모 모양으로 탐색
		for (int i = -k; i <= k; ++i) {
			for (int j = -(k - abs(i)); j <= (k - abs(i)); ++j) {
				int newY = y + i;
				int newX = x + j;
				if (newY >= 0 && newY < N && newX >= 0 && newX < N) {
					goldCnt += mineArea[newY][newX];
				}
			}
		}

		// 손해 안 보는 경우
		if (goldCnt * M >= GetCost(k)) {
			maxGold = max(maxGold, goldCnt);
		}
	}

	return maxGold;
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> mineArea[y][x];
		}
	}

	// 손해 없이 채굴할 수 있는 가장 많은 금의 개수를 구함
	int numOfGold = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			numOfGold = max(numOfGold, GetNumOfGold(y, x, N, M));
		}
	}
	
	cout << numOfGold;
}