#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
} node;

node *head = NULL;

node *createNode(int);
node *checkCycle(); // Function to detect and handle cycle (to be implemented by you)
void createCyclicList();
void displayList();
void freeList();

int main()
{
    createCyclicList(); // Create a hardcoded list with a cycle
    displayList();      // Display the list

    if (!checkCycle()) // Call the function to detect a cycle
        cout << "\n\tIn this list cycle not present!"
             << endl;
    else
        cout << "\n\tIn this list cycle present!"
             << endl;

    freeList(); // Cleanup
    cout << "\tExiting...\n"
         << endl;

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
    node5->next = node2; // Change to node2 to create a cycle
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
    while (p != NULL && count < 12)
    {
        cout << p->data << "->";
        p = p->next;
        count++;
    }
    if (count == 12)
        cout << "...\n";
    else
        cout << "NULL\n";
}

void freeList()
{
    if (!head)
    {
        cout << "\n\tList is already empty." << endl;
        return;
    }

    // Use checkCycle to detect the meeting point if there's a cycle
    node *meetingPoint = checkCycle();

    if (meetingPoint != NULL) // If a cycle exists
    {
        node *slow = head;

        // Find the start of the cycle
        while (slow->next != meetingPoint->next)
        {
            slow = slow->next;
            meetingPoint = meetingPoint->next;
        }

        // Break the cycle
        meetingPoint->next = NULL;
    }

    // Free the list nodes
    node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    cout << "\n\tAll nodes freed." << endl;
}

// Placeholder function for cycle detection
node *checkCycle()
{
    node *turtle = head, *rabbit = head;
    while (rabbit != NULL && rabbit->next != NULL)
    {
        turtle = turtle->next;
        rabbit = rabbit->next->next;

        if (turtle == rabbit)
            return turtle;
    }
    return NULL;
}
