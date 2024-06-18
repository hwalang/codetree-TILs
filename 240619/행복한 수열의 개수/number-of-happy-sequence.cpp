#include <iostream>

using namespace std;

const int MAX_N = 100;

int arr[MAX_N][MAX_N];

// 1차원 수열에서 행복한 수열이 존재하는 경우를 판단한다.
bool CheckHappySeq(const int seq[], int length, int M)
{
	int sameCnt = 1;

	for (int i = 1; i < length; ++i) {
		if (seq[i] == seq[i - 1]) {
			sameCnt++;
		}
		else {
			sameCnt = 1;
		}

		if (sameCnt >= M) {
			return true;
		}
	}

	return false;
}

int GetNumOfHappySeq(int N, int M)
{
	int hNum = 0;

	// 행에 존재하는 행복한 수열이 몇 개?
	for (int row = 0; row < N; ++row) {
		if (CheckHappySeq(arr[row], N, M)) {
			hNum++;
		}
	}

	// 열에 존재하는 행복한 수열이 몇 개?
	for (int col = 0; col < N; ++col) {
		int colSeq[MAX_N];

		// arr의 열을 colSeq인 1차원 배열로 옮긴다.
		for (int row = 0; row < N; ++row) {	
			colSeq[row] = arr[row][col];
		}

		if (CheckHappySeq(colSeq, N, M)) {
			hNum++;
		}
	}

	return hNum;
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;
	if (M == 1) {
		ans = N * 2;
	}
	else {
		ans = GetNumOfHappySeq(N, M);
	}
	 
	cout << ans;
}