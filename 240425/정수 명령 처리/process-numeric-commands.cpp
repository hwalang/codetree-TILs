#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<int> _stack;
    int size;
    string order;
    int input;

    cin >> size;
    while (size <= 0)
    {
        cin >> order;
        switch (order)
        {
            case "push":
                cin >> input;
                _stack.push(input);
                break;
            case "size":
                cout << _stack.size() << endl;
                break;
            case "empty":
                int out = _stack.empty() ? 1 : 0;
                cout << out << endl;
                break;
            case "pop":
                int out = _stack.top();
                _stack.pop();
                cout << out << endl;
                break;
            case "top":
                cout << _stack.top() << endl;
                break;
        }
        

        --size;
    }

    return 0;
}