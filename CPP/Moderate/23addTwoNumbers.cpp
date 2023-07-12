#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* addTwoNumbers(Node* num1, Node* num2) {
    int carry = 0;
    if (num1 == nullptr) {
        return num2;
    } else if (num2 == nullptr) {
        return num1;
    }

    Node* head = new Node(-1);
    Node* duplicate = head;

    while (num1 || num2 || carry != 0) {
        int sum = 0;
        if (num1 != nullptr) {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2 != nullptr) {
            sum += num2->data;
            num2 = num2->next;
        }
        // adding previous carry here;
        sum += carry;
        carry = sum / 10;

        Node* newElement = new Node(sum % 10);
        duplicate->next = newElement;
        duplicate = duplicate->next;
    }

    return head->next;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    int n1, n2;
    std::cin >> n1;

    Node* num1 = nullptr;
    Node* num1Tail = nullptr;
    for (int i = 0; i < n1; i++) {
        int num;
        std::cin >> num;

        Node* newNode = new Node(num);
        if (num1 == nullptr) {
            num1 = newNode;
            num1Tail = newNode;
        } else {
            num1Tail->next = newNode;
            num1Tail = num1Tail->next;
        }
    }

    std::cin >> n2;

    Node* num2 = nullptr;
    Node* num2Tail = nullptr;
    for (int i = 0; i < n2; i++) {
        int num;
        std::cin >> num;

        Node* newNode = new Node(num);
        if (num2 == nullptr) {
            num2 = newNode;
            num2Tail = newNode;
        } else {
            num2Tail->next = newNode;
            num2Tail = num2Tail->next;
        }
    }

    Node* result = addTwoNumbers(num1, num2);
    printList(result);

    return 0;
}
