#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> _stack;
string input;

bool solution()
{
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] == '(')
        {
            _stack.push(input[i]);
        }
        else if (input[i] == ')')
        {
            if (_stack.empty()) return false;

            if (_stack.top() == '(')
            {
                _stack.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (!_stack.empty()) return false;

    return true;
}

int main() {
    
    cin >> input;

    if (solution())
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}