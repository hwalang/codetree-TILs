#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_LOC 100

int N;
char loc[MAX_LOC + 1];

int main() {

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int idx; char placard;
		cin >> idx >> placard;

		loc[idx] = placard;
	}

	int max_picture_size = 0;
	// 1. G로만 구성 + 사진의 최대 크기
	for (int i = 0; i < MAX_LOC; ++i) {
		if (loc[i] != 'G') continue;
		int start_loc = i;
		int end_loc = i;
		for (int j = i + 1; j <= MAX_LOC; ++j) {
			if (loc[j] == 'G') {
				end_loc = j;
			}
			else if (loc[j] == 'H') break;
		}
		int picture_size = end_loc - start_loc;
		max_picture_size = max(max_picture_size, picture_size);
	}

	// 2. H로만 구성 + 사진의 최대 크기
	for (int i = 0; i < MAX_LOC; ++i) {
		if (loc[i] != 'H') continue;
		int start_loc = i;
		int end_loc = i;
		for (int j = i + 1; j <= MAX_LOC; ++j) {
			if (loc[j] == 'H') {
				end_loc = j;
			}
			else if (loc[j] == 'G') break;
		}
		int picture_size = end_loc - start_loc;
		max_picture_size = max(max_picture_size, picture_size);
	}

	// 3. G, H가 같은 수로 구성 + 사진의 최대 크기
	for (int i = 0; i < MAX_LOC; ++i) {
		int cntG = 0;
		int cntH = 0;
		if (loc[i] == 'G') ++cntG;
		else if (loc[i] == 'H') ++cntH;
		else continue;
		int start_loc = i;
		int end_loc = i;

		for (int j = i + 1; j <= MAX_LOC; ++j) {
			if (loc[j] == 'G') ++cntG;
			else if (loc[j] == 'H') ++cntH;
			else continue;

			if ( (loc[j] == 'G' || loc[j] == 'H') && cntG == cntH) end_loc = j;
		}

		int picture_size = end_loc - start_loc;
		max_picture_size = max(max_picture_size, picture_size);
	}

	cout << max_picture_size;

	return 0;
}