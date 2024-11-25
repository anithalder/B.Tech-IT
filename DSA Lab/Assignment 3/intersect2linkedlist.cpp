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

Node *head1 = NULL, *head2 = NULL;

Node *findIntersect();
void createList();
void displayList(Node *);
void freeList();

int main()
{
    createList();
    cout << "\n1st List: ";
    displayList(head1);
    cout << "2nd List: ";
    displayList(head2);

    Node *intersect = findIntersect();

    if (intersect)
        cout << "The intersect node is: " << intersect->data << '\n'
             << endl;
    else
        cout << "\tNo intersection between the two lists." << endl;

    freeList(); // Cleanup
    cout << "Exiting...\n";

    return 0;
}

void createList()
{
    // Create Nodes

    // 1st list
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);

    // 2nd List
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);

    // Link nodes to form a list
    head1 = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    head2 = node6;
    node6->next = node7;
    node7->next = node8;

    node8->next = node2;
    node5->next = NULL;
}

void freeList()
{
    Node *temp;
    while (head1 != nullptr)
    {
        temp = head1;
        head1 = head1->next;
        delete temp;
    }
    while (head2 != nullptr)
    {
        temp = head2;
        head2 = head2->next;
        delete temp;
    }
    cout << "\nAll nodes freed." << endl;
}

void displayList(Node *head)
{
    if (!head)
    {
        cout << "Empty!\n"
             << endl;
        return;
    }
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "NULL\n"
         << endl;
}

Node *findIntersect()
{
    Node *p1 = head1, *p2 = head2;

    // Traverse both lists. When one pointer reaches the end, switch to the other list.
    while (p1 != p2)
    {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }

    // Either intersection node or NULL (if no intersection)
    return p1;
}
