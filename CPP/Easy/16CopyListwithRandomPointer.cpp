#include <iostream>
using namespace std;

template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode<T>* random;

    LinkedListNode(T data) {
        this->data = data;
        this->next = nullptr;
        this->random = nullptr;
    }
};

LinkedListNode<int>* cloneRandomList(LinkedListNode<int>* head) {
    LinkedListNode<int>* ans;
    bool f = true;
    while (head != nullptr) {
        LinkedListNode<int>* tmp = new LinkedListNode<int>(head->data);
        if (f) {
            ans = tmp;
            f = false;
        }
        tmp->next = head->next;
        tmp->random = head->random;
        head = head->next;
        tmp = tmp->next;
    }
    return ans;
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

    cout << "Original Linked List: ";
    LinkedListNode<int>* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    LinkedListNode<int>* clonedList = cloneRandomList(head);

    cout << "Cloned Linked List: ";
    current = clonedList;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
