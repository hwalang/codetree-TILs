#include <iostream>
#include <list>

using namespace std;

int N, M;
list<char> li;
list<char>::iterator it;

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		char input;
		cin >> input;
		li.push_back(input);
	}
	it = li.end();

	for (int i = 0; i < M; ++i) {
		char order;
		cin >> order;
		
		if (order == 'L') {
			if (it == li.begin()) continue;
			it--;
		}
		else if (order == 'R') {
			if (it == li.end()) continue;
			it++;
		}
		else if (order == 'D') {
			if (it == li.end()) continue;
			li.erase(it);
		}
		else {
			char input;
			cin >> input;
			li.insert(it, input);
		}
	}

	for (it = li.begin(); it != li.end(); ++it) {
		cout << *it;
	}

}