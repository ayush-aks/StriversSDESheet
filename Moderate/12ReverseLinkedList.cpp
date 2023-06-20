#include <iostream>

template <typename T>
struct LinkedListNode {
    T data;
    LinkedListNode<T> *next;

    LinkedListNode(const T &value) : data(value), next(nullptr) {}
};

// Function to reverse a linked list
template <typename T>
LinkedListNode<T> *reverseLinkedList(LinkedListNode<T> *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    LinkedListNode<T> *prev = nullptr;
    LinkedListNode<T> *curr = head;
    LinkedListNode<T> *forward = nullptr;

    while (curr != nullptr) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

int main() {
    int n;
    std::cin >> n;  // Number of elements in the linked list

    LinkedListNode<int> *head = nullptr;
    LinkedListNode<int> *tail = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        std::cin >> data;  // Read data for each node

        // Create a new node
        LinkedListNode<int> *newNode = new LinkedListNode<int>(data);

        if (head == nullptr) {
            // First node in the list
            head = newNode;
            tail = newNode;
        } else {
            // Append new node to the end of the list
            tail->next = newNode;
            tail = tail->next;
        }
    }

    // Reverse the linked list
    LinkedListNode<int> *reversedHead = reverseLinkedList(head);

    // Print the reversed linked list
    LinkedListNode<int> *current = reversedHead;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    // Clean up memory (delete the linked list)
    current = reversedHead;
    while (current != nullptr) {
        LinkedListNode<int> *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
