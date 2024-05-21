#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue<int> q;
string input_order;
int order_size;

void Solution(string order)
{
    int input_n;
    if (order == "push")
    {
        cin >> input_n;
        q.push(input_n);
    }
    else if (order == "pop")
    {
        cout << q.front() << endl;
        q.pop();
    }
    else if (order == "size")
    {
        cout << q.size() << endl;
    }
    else if (order == "empty")
    {
        if (q.empty()) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else if (order == "front")
    {
        cout << q.front() << endl;
    }
}

int main() {
    
    cin >> order_size;
    for (int i = 0; i < order_size; ++i)
    {
        cin >> input_order;
        Solution(input_order);
    }

    return 0;
}