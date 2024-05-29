#include <iostream>
#include <string>
#include <list>
using namespace std;

int N, M;
string commands;
list<char> breads;
list<char>::iterator it;

void Init()
{
    cin >> N >> M >> commands;
    for (int i = 0; i < commands.length(); ++i) {
        breads.push_back(commands[i]);
    }
    it = breads.end();
}

void ExecuteCommand()
{
    while (M--) {
        char command;
        cin >> command;

        if (command == 'L') {
            if (it != breads.begin()) {
                it--;
            }
        }
        else if (command == 'R') {
            if (it != breads.end()) {
                it++;
            }
        }
        else if (command == 'D') {
            if (it != breads.end()) {
                it = breads.erase(it);
            }
        }
        else if (command == 'P') {
            char insertC;
            cin >> insertC;
            breads.insert(it, insertC);
        }
    }
}

void PrintIterator()
{
    for (it = breads.begin(); it != breads.end(); ++it) {
        cout << *it;
    }
}

int main() 
{
    Init();
    ExecuteCommand();
    PrintIterator();

    return 0;
}