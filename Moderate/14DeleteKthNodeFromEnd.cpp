#include <iostream>

// Node definition
struct Node {
    int data;
    Node* next;
};

// Function to remove the kth node from the end of a linked list
Node* removeKthNode(Node* head, int k) {
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    // Move the fast pointer k nodes ahead
    for (int i = 0; i < k; i++) {
        if (fast == NULL) {
            return head; // k is greater than the length of the list, return head as is
        }
        fast = fast->next;
    }

    // Move both pointers simultaneously until fast reaches the end
    while (fast != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    // If prev is still NULL, it means we need to remove the head node
    if (prev == NULL) {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    // Remove the kth node from the end
    prev->next = slow->next;
    delete slow;

    return head;
}

int main() {
    // Create a sample linked list
    Node* head = new Node;
    Node* curr = head;

    // Input linked list size and k
    int size, k;
    std::cin >> size >> k;

    // Input list elements
    for (int i = 0; i < size; i++) {
        int data;
        std::cin >> data;

        curr->data = data;
        if (i < size - 1) {
            curr->next = new Node;
            curr = curr->next;
        }
    }
    curr->next = NULL;

    // Call the removeKthNode function
    head = removeKthNode(head, k);

    // Print the resulting linked list
    curr = head;
    while (curr != NULL) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;

    // Clean up the memory
    curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
