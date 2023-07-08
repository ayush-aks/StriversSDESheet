#include <iostream>

template<typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
Node<T>* sortTwoLists(Node<T>* first, Node<T>* second) {
    if (first == nullptr)
        return second;

    if (second == nullptr)
        return first;

    if (first->data > second->data)
        std::swap(first, second);

    Node<T>* res = first;

    while (first != nullptr && second != nullptr) {
        Node<T>* temp = nullptr;

        while (first != nullptr && first->data <= second->data) {
            temp = first;
            first = first->next;
        }

        temp->next = second;
        std::swap(first, second);
    }

    return res;
}

template<typename T>
void printList(Node<T>* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "-1\n";
}

int main() {
    int n;
    std::cin >> n;

    Node<int>* firstHead = nullptr;
    Node<int>* secondHead = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;

        Node<int>* newNode = new Node<int>(x);

        if (i == 0)
            firstHead = newNode;
        else
            secondHead->next = newNode;

        secondHead = newNode;
    }

    Node<int>* thirdHead = nullptr;
    Node<int>* fourthHead = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;

        Node<int>* newNode = new Node<int>(x);

        if (i == 0)
            thirdHead = newNode;
        else
            fourthHead->next = newNode;

        fourthHead = newNode;
    }

    Node<int>* result = sortTwoLists(firstHead, thirdHead);
    printList(result);

    return 0;
}
