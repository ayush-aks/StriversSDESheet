#include <iostream>
using namespace std;

template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T>* next;

    LinkedListNode(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

bool isPalindrome(LinkedListNode<int>* head) {
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    LinkedListNode<int>* temp = slow;
    LinkedListNode<int>* prev = nullptr;

    while (temp != nullptr) {
        LinkedListNode<int>* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    while (head != slow) {
        if (prev->data != head->data) {
            return false;
        }
        head = head->next;
        prev = prev->next;
    }

    return true;
}

int main() {
    LinkedListNode<int>* head = nullptr;
    LinkedListNode<int>* tail = nullptr;

    cout << "Enter the elements (-1 to stop): ";
    int data;
    while (cin >> data && data != -1) {
        LinkedListNode<int>* newNode = new LinkedListNode<int>(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Result: " << (isPalindrome(head) ? "true" : "false") << endl;

    return 0;
}
