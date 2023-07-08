#include <iostream>

struct Node {
    int data;
    Node* next;
};

bool detectCycle(Node* head) {
    if (head == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            return true;
        }
    }

    return false;
}

int main() {
    // Create the linked list
    Node* head = new Node{1, nullptr};
    Node* node2 = new Node{2, nullptr};
    Node* node3 = new Node{3, nullptr};
    Node* node4 = new Node{4, nullptr};

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    // Creating a cycle in the linked list
    node4->next = node2;

    bool hasCycle = detectCycle(head);

    std::cout << std::boolalpha;
    std::cout << "Output: " << hasCycle << std::endl;

    // Clean up the memory
    node4->next = nullptr;
    delete node4;
    node3->next = nullptr;
    delete node3;
    node2->next = nullptr;
    delete node2;
    head->next = nullptr;
    delete head;

    return 0;
}
