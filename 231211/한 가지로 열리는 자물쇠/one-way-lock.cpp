#include <iostream>
#include <cmath>

using namespace std;

int N, a, b, c;
int ans;

int main() {

	cin >> N;
	cin >> a >> b >> c;
	
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int k = 1; k <= N; ++k) {
				// +- 2 이내의 수인 경우
				if (abs(i - a) <= 2 || abs(j - b) <= 2 || abs(k - c) <= 2)
					ans++;
			}
		}
	}

	cout << ans;

	return 0;
}