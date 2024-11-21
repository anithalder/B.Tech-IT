#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
} node;

node *head = NULL;

node *createNode(int);
void createCyclicList();
void displayList();
void freeList();
bool checkCycle(); // Function to detect and handle cycle (to be implemented by you)

int main()
{
    createCyclicList(); // Create a hardcoded list with a cycle
    cout << "\nThe list has been created with a cycle.\n";

    if (checkCycle()) // Call the function to detect a cycle
    {
        cout << "\n\tIn this list cycle present!"
             << endl;
    }
    else
    {
        cout << "\n\tIn this list cycle not present!"
             << endl;
    }

    freeList(); // Cleanup
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

void createCyclicList()
{
    // Create nodes
    node *node1 = createNode(1);
    node *node2 = createNode(2);
    node *node3 = createNode(3);
    node *node4 = createNode(4);
    node *node5 = createNode(5);

    // Link nodes to form a list
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Create a cycle (node5 points back to node2)
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

    node *p = head;
    int count = 0; // Prevent infinite loop for cyclic list
    cout << "\n\tList is: ";
    while (p != NULL && count < 15)
    {
        cout << p->data << "->";
        p = p->next;
        count++;
    }
    if (count == 15)
        cout << "... (cycle detected)\n";
    else
        cout << "NULL\n";
}

void freeList()
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

// Placeholder function for cycle detection
bool checkCycle()
{
    node *turtle = head, *rabbit = head;

    while (rabbit != NULL && rabbit->next != NULL)
    {
        turtle = turtle->next;
        rabbit = rabbit->next->next;

        if (turtle == rabbit)
        {
            return true;
        }
    }
    return false;
}
