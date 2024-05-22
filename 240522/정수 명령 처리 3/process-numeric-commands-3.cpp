#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> dq;
int N;

void Input()
{
	cin >> N;
}

void HandleCommand(string command)
{
	int input_num;
	if (command == "push_front")
	{
		cin >> input_num;
		dq.push_front(input_num);
	}
	else if (command == "push_back")
	{
		cin >> input_num;
		dq.push_back(input_num);
	}
	else if (command == "pop_front")
	{
		cout << dq.front() << endl;
		dq.pop_front();
	}
	else if (command == "pop_back")
	{
		cout << dq.back() << endl;
		dq.pop_back();
	}
	else if (command == "size")
	{
		cout << dq.size() << endl;
	}
	else if (command == "empty")
	{
		if (dq.empty()) cout << 1 << endl;
		else 			cout << 0 << endl;
	}
	else if (command == "front")
	{
		cout << dq.front() << endl;
	}
	else if (command == "back")
	{
		cout << dq.back() << endl;
	}
}

int main() {
    Input();
	for (int i = 0; i < N; ++i)
	{
		string command;
		cin >> command;
		HandleCommand(command);
	}
    return 0;
}