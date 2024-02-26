#include <iostream>

using namespace std;

const int MAX_N = 100;

int N;
int arr[MAX_N];

int main() {

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	for (int i = 0; i < N; ++i) {

		for (int j = 0; j < N - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		
	}

	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
}