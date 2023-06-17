#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node* next, Node* child) : data(x), next(next), child(child) {}
};

Node* mergeTwoLists(Node* a, Node* b) {
    Node* temp = new Node(0);
    Node* res = temp;

    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        } else {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
    }

    if (a)
        temp->child = a;
    else
        temp->child = b;

    return res->child;
}

Node* flattenLinkedList(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* L2 = flattenLinkedList(head->next);

    head->next = NULL;

    Node* nhead = mergeTwoLists(head, L2);

    return nhead;
}

int main() {
    int n;
    cout << "Enter the number of linked lists: ";
    cin >> n;

    Node* head = nullptr;
    Node* current = nullptr;

    for (int i = 0; i < n; i++) {
        int m;
        cout << "Enter the number of elements in linked list " << i + 1 << ": ";
        cin >> m;

        Node* subHead = nullptr;
        Node* subCurrent = nullptr;

        for (int j = 0; j < m; j++) {
            int data;
            cout << "Enter element " << j + 1 << " of linked list " << i + 1 << ": ";
            cin >> data;

            Node* newNode = new Node(data);

            if (subHead == nullptr) {
                subHead = newNode;
                subCurrent = newNode;
            } else {
                subCurrent->next = newNode;
                subCurrent = newNode;
            }
        }

        if (head == nullptr) {
            head = subHead;
            current = subCurrent;
        } else {
            current->child = subHead;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = subHead;
            current = subCurrent;
        }
    }

    cout << "Flattened Linked List: ";
    Node* flattenedHead = flattenLinkedList(head);
    current = flattenedHead;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
