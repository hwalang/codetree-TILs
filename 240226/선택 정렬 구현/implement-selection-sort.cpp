#include <iostream>

using namespace std;

const int MAX_N = 100;

int N;
int arr[MAX_N];

void SelectionSort() {
    for (int i = 0; i < N; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < N; ++j) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    SelectionSort();

    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    
    return 0;
}