#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
} node;

node *head1 = NULL;
node *head2 = NULL;

node *createNode(int);
node *createList();
node *mergeList();
void displayList(node *);
void freeList(node *);

int main()
{
    cout << "\nFor the 1st list\n";
    cout << "-----------------\n";
    head1 = createList();

    cout << "\nFor the 2nd list\n";
    cout << "-----------------\n";
    head2 = createList();

    cout << '\n';

    cout << "1st List: ";
    displayList(head1);
    cout << "2nd List: ";
    displayList(head2);
    cout << "Merge List: ";
    node *mergedList = mergeList();
    displayList(mergedList);

    freeList(mergedList); // Cleanup
    cout << "Exiting...\n";

    return 0;
}

node *createNode(int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

node *createList()
{
    int n, value;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "List size must be greater than 0.\n";
        return NULL;
    }

    // Create the head node
    cout << "Enter value for node 1: ";
    cin >> value;
    node *head = createNode(value);
    node *current = head;

    // Create the remaining nodes
    for (int i = 2; i <= n; ++i)
    {
        cout << "Enter value for node " << i << ": ";
        cin >> value;
        current->next = createNode(value);
        current = current->next;
    }

    return head;
}

void freeList(node *head)
{
    node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "\nAll nodes freed." << endl;
}

void displayList(node *head)
{
    if (!head)
    {
        cout << "Empty!\n"
             << endl;
        return;
    }
    node *p = head;
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "NULL\n"
         << endl;
}

node *mergeList()
{
    node *p1 = head1, *p2 = head2;
    node *dummy = new node(), *p3 = dummy;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummy->next;
}