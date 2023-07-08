#include <iostream>
using namespace std;

/*
1 2 3 4 5 6 7 8 9 10 11 -1
3
2 3 4

*/

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int calc(Node* head) {
    Node* p = head;
    int l = 0;

    while (p) {
        l++;
        p = p->next;
    }

    return l;
}

Node* reverse(Node* head) {
    Node* p = head, * nxt, * prev = NULL;

    while (p) {
        nxt = p->next;
        p->next = prev;

        prev = p;
        p = nxt;
    }

    return prev;
}

Node* getListAfterReverseOperation(Node* head, int n, int b[]) {
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* p = dummy, * curr, * nxt;

    int len = calc(head);
    for (int i = 0; i < n; i++) {
        if (len == 0)
            break;

        if (b[i] <= len) {
            curr = p->next;
            nxt = curr->next;

            if (b[i] == 0)
                continue;

            for (int j = 0; j < b[i] - 1; j++) {
                curr->next = nxt->next;
                nxt->next = p->next;

                p->next = nxt;
                nxt = curr->next;
            }

            len -= b[i];
            p = curr;
        } else if (len <= b[i]) {
            p->next = reverse(p->next);
            len = 0;
        }
    }

    return dummy->next;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter the elements (-1 to stop): ";
    int data;
    while (cin >> data && data != -1) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int b[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cout << "Original List: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    Node* result = getListAfterReverseOperation(head, n, b);

    cout << "List after Reverse Operation: ";
    current = result;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "-1" << endl;

    return 0;
}
