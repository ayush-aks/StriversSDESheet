#include <bits/stdc++.h>
using namespace std;



template <typename T>
class LinkedListNode
{
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
};


void deleteNode(LinkedListNode<int> * node)
{
    node->data = node->next->data;

    LinkedListNode<int> *temp = node->next;

    node->next=node->next->next;

    delete temp;
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

    LinkedListNode<int>* nodeToDelete = head->next;
    cout << "Deleting node with value " << nodeToDelete->data << endl;
    deleteNode(nodeToDelete);

    cout << "Linked List after deletion: ";
    current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
