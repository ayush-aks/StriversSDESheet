#include <bits/stdc++.h>
using namespace std;


/*
Sample Input 1 :
5
1 2 3 4 5
Sample Output 1 :
3 4 5
*/
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *findMiddle(Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* temp1 = head;
    Node* temp2 = head;

    while(temp1!=NULL && temp1->next!=NULL)
    {
        temp1 = temp1->next->next;
        temp2 = temp2->next;
    }
    return temp2;
}


int main()
{
    int n;
   cout << "Enter the number of elements: ";
   cin >> n;

   Node* head = nullptr;
   Node* tail = nullptr;

   cout << "Enter the elements: ";
   for (int i = 0; i < n; i++) {
       int data;
       cin >> data;

       Node* newNode = new Node(data);

       if (head == nullptr) {
           head = newNode;
           tail = newNode;
       } else {
           tail->next = newNode;
           tail = newNode;
       }
   }

   Node* middle = findMiddle(head);

   if (middle != nullptr) {
       cout << "Middle element: " << middle->data << endl;
   } else {
       cout << "List is empty!" << endl;
   }
    return 0;
}
