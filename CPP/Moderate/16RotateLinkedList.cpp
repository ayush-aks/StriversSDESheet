#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

Node* rotate(Node* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }

    Node* curr = head;
    int len = 1;

    while (curr->next != nullptr) {
        curr = curr->next;
        len++;
    }
    curr->next = head;
    k = k % len;
    k = len - k;

    while (k--) {
        curr = curr->next;
    }
    head = curr->next;
    curr->next = nullptr;
    return head;
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        Node* newNode = createNode(num);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k;
    std::cout << "Enter the rotation count: ";
    std::cin >> k;

    std::cout << "Original List: ";
    displayList(head);

    head = rotate(head, k);

    std::cout << "Rotated List: ";
    displayList(head);

    return 0;
}
