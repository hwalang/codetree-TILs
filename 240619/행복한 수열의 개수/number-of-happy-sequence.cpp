#include <iostream>

using namespace std;

const int MAX_N = 100;

int arr[MAX_N][MAX_N];

int GetNumOfHappySeq(int N, int M)
{
	int hNum = 0;

	// 열에 존재하는 행복한 수열이 몇 개?
	for (int row = 0; row < N; ++row) {		// 행을 이동하면서 연속된 m개의 숫자가 같은지 판단

		int sameCnt = 1;
		
		for (int col = 1; col < N; ++col) {
			if (sameCnt == M) {
				hNum++;
				break;
			}

			int prevNum = arr[col - 1][row];
			int curNum = arr[col][row];
			

			if (prevNum == curNum) {
				sameCnt++;
			}
			else {
				sameCnt = 1;
			}

			/*cout << "----------------------------\n";
			cout << "(" << col - 1 << ", " << row << "): " << prevNum << endl;
			cout << "(" << col << ", " << row << "): " << curNum << endl;
			cout << "same count: " << sameCnt << endl;
			cout << "----------------------------\n";*/
		}
	}

	/*cout << "------------- col ---------------\n";*/

	for (int col = 0; col < N; ++col) {		// 열을 이동하면서 연속된 m개의 숫자가 같은지 판단

		int sameCnt = 1;

		for (int row = 1; row < N; ++row) {
			
			int prevNum = arr[col][row - 1];
			int curNum = arr[col][row];


			if (prevNum == curNum) {
				sameCnt++;
			}
			else {
				sameCnt = 1;
			}

			if (sameCnt >= M) {
				hNum++;
				break;
			}

			/*cout << "----------------------------\n";
			cout << "(" << col << ", " << row - 1 << "): " << prevNum << endl;
			cout << "(" << col << ", " << row << "): " << curNum << endl;
			cout << "same count: " << sameCnt << endl;
			cout << "----------------------------\n";*/
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