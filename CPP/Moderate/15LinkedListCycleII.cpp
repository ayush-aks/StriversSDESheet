#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* firstNode(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    Node* fast = head;
    Node* slow = head;
    Node* temp = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) { // we detect the cycle in the given linked list.
            while (slow != temp) {
                slow = slow->next;
                temp = temp->next;
            }
            return temp;
        }
    }

    return NULL;
}

int main() {
    // Create the linked list with a cycle
    Node* head = new Node();
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();

    head->data = 1;
    head->next = node1;

    node1->data = 2;
    node1->next = node2;

    node2->data = 3;
    node2->next = node3;

    node3->data = 4;
    node3->next = node4;

    node4->data = -1;
    node4->next = node1; // create a cycle

    // Call the function to find the first node of the cycle
    Node* result = firstNode(head);

    // Print the output
    if (result != NULL) {
        std::cout << "First node of the cycle: " << result->data << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    // Clean up the memory
    delete head;
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
