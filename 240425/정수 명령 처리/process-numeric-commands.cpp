#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<int> _stack;

    int size;
    cin >> size;

    while (size > 0)
    {
        int out;
        string order;
        int input;
        cin >> order;
        if (order == "push")
        {
            cin >> input;
            _stack.push(input);
        }
        else if (order == "size")
        {
            cout << _stack.size() << endl;
        }
        else if (order == "empty")
        {
            out = _stack.empty() ? 1 : 0;   
            cout << out << endl;
        }
        else if (order == "pop")
        {
            out = _stack.top();
            _stack.pop();
            cout << out << endl;
        }
        else
        {
            cout << _stack.top() << endl;
        }
        --size;
    }

    return 0;
}