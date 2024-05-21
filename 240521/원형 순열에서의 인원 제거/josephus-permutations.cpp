#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int total, removed_num;

void Input()
{
	cin >> total >> removed_num;
	for (int i = 1; i <= total; ++i)
	{
		q.push(i);
	}
}

void PrintRemovedPerson()
{
	while (q.size() >= 1)
	{
		for (int i = 1; i < removed_num; ++i)
		{
			q.push(q.front());
			q.pop();
		}
		
		cout << q.front() << " ";
		q.pop();
	}
}

int main()
{
	Input();
	PrintRemovedPerson();
}