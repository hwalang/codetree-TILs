#include <iostream>
#include <list>
#include <string>

int N, inputNum;
std::string inputStr;
std::list<int> list;




int main() {

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> inputStr;
        if ("push_front" == inputStr) {
            std::cin >> inputNum;
            list.push_front(inputNum);
        }
        else if ("push_back" == inputStr) {
            std::cin >> inputNum;
            list.push_back(inputNum);
        }
        else if ("pop_front" == inputStr) {
            int num = list.front();
            list.pop_front();
            std::cout << num << "\n";
        }
        else if ("pop_back" == inputStr) {
            int num = list.back();
            list.pop_back();
            std::cout << num << "\n";
        }
        else if ("front" == inputStr) {
            std::cout << list.front() << "\n";
        }
        else if ("back" == inputStr) {
            std::cout << list.back() << "\n";
        }
        else if ("size" == inputStr) {
            std::cout << list.size() << "\n";
        }
        else if ("empty" == inputStr) {
            if (list.empty()) std::cout << 1 << "\n";
            else std::cout << 0 << "\n";
        }
    }

    return 0;
}