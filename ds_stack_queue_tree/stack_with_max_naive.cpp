#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <climits>
using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> stack;
    vector<int> max_stack;

  public:
    int max_amount = INT_MIN;

    void Push(int value) {
        stack.push_back(value);
        if (value>max_amount){
          max_amount = value;
        }
        max_stack.push_back(max_amount);
    }

    void Pop() {
        assert(stack.size());
        stack.pop_back();
        max_stack.pop_back();

    }

    int Max() const {
        assert(stack.size());
        return max_stack.back();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;


    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
