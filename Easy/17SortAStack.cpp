#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int>& stack, int num) {
    if (stack.empty() || (!stack.empty() && stack.top() < num)) {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    sortedInsert(stack, num);
    stack.push(n);
}

void sortStack(stack<int>& stack) {
    if (stack.empty()) {
        return;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortedInsert(stack, num);
}

int main() {
    stack<int> stk;

    cout << "Enter the elements (-1 to stop): ";
    int num;
    while (cin >> num && num != -1) {
        stk.push(num);
    }

    cout << "Original Stack: ";
    stack<int> originalStack = stk;
    while (!originalStack.empty()) {
        cout << originalStack.top() << " ";
        originalStack.pop();
    }
    cout << endl;

    sortStack(stk);

    cout << "Sorted Stack: ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    return 0;
}
