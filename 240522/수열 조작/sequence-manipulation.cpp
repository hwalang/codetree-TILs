#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int N;

void Input()
{
	cin >> N;
}

void Init()
{
	for (int i = 1; i <= N; ++i)
	{
		q.push(i);
	}
}

int GetRemainedElement()
{
	while (q.size() != 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}

	return q.front();
}

int main()
{
	Input();
	Init();
	cout << GetRemainedElement();
}