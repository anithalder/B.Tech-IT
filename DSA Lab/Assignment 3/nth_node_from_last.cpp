#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;

    Node(int data, Node *next = NULL)
    {
        this->data = data;
        this->next = next;
    }
} Node;

Node *head = NULL;

Node *createNode(int);
Node *findNthFromEnd(int);
void createList();
void displayList();
void freeList();

int main()
{
    cout << '\n';

    createList();
    displayList();

    int n;
    cout << "\tEnter the n'th node: ";
    cin >> n;

    Node *result = findNthFromEnd(n);
    if (result)
        cout << "\tThe " << n << "'th node from end of list is: "
             << result->data << endl;
    else
        cout << "\n\tInvalid value of n!" << endl;

    freeList(); // Cleanup
    cout << "\tExiting...\n\n";

    return 0;
}

Node *createNode(int data)
{
    return new Node(data, NULL);
}

void createList()
{
    // Create Nodes
    Node *node1 = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(4);
    Node *node5 = createNode(5);

    // Link nodes to form a list
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node5->next = NULL;
}

void displayList()
{
    if (!head)
    {
        cout << "\n\tList is empty!\n"
             << endl;
        return;
    }
    Node *p = head;
    cout << "\n\tList is: ";
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "NULL\n"
         << endl;
}

void freeList()
{
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "\n\tAll nodes freed." << endl;
}

Node *findNthFromEnd(int n)
{
    Node *slow = head, *fast = head;

    for (int i = 0; i < n; i++)
    {
        if (fast == NULL)
            return NULL;
        fast = fast->next;
    }

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}