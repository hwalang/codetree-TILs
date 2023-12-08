#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define INSTRUCTION1 "push_back"
#define INSTRUCTION2 "pop_back"
#define INSTRUCTION3 "size"
#define INSTRUCTION4 "get"

int N;
vector<int> v;

int main() {
	
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string order; int num;
		cin >> order;
		
		if (order == INSTRUCTION1) {
			cin >> num;
			v.push_back(num);
		}
		else if (order == INSTRUCTION2) {
			v.pop_back();
		}
		else if (order == INSTRUCTION3) {
			cout << v.size() << endl;
		}
		else if (order == INSTRUCTION4) {
			cin >> num;
			cout << v[num - 1] << endl;
		}
	}

	return 0;
}