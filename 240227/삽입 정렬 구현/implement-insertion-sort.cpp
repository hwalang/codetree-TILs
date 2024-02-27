#include <iostream>

using namespace std;

const int MAX_N = 100;

int N;
int arr[MAX_N];

void Insertion_sort() {
    for (int i = 1; i < N; ++i) {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j +  1] = key;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    
    Insertion_sort();

    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    return 0;
}