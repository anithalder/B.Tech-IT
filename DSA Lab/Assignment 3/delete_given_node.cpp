#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node;
Node *head = NULL;

Node *createNode(int);
void insertNode(int);
void displayList();
void freeList();
void deleteNodeByValue();

int main()
{
    int choice, value;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete By Value\n";
        cout << "0. Exit\n";
        displayList();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertNode(value);
            break;
        case 2:
            deleteNodeByValue();
            break;
        case 0:
            freeList();
            cout << "Exiting...\n"
                 << endl;
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertNode(int data)
{
    Node *p, *temp = createNode(data);
    if (head == NULL)
        head = temp;
    else
    {
        p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }
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

void deleteNodeByValue()
{
    int value;
    cout << "Enter the value of the node to delete: ";
    cin >> value;

    if (head == NULL)
    {
        cout << "\n\tThe list is empty. Nothing to delete.\n"
             << endl;
        return;
    }

    // Special case: if the head node contains the value
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next; // Move head to the next node
        free(temp);        // Free the old head
        // cout << "Node with value " << value << " deleted from the head." << endl;
        return;
    }

    // General case: traverse the list to find and delete the node
    Node *currNode = head->next; // Start from the second node
    Node *prevNode = head;       // Previous node starts as head

    while (currNode != NULL)
    {
        if (currNode->data == value)
        {
            prevNode->next = currNode->next; // Bypass the current node
            free(currNode);                  // Free the node
            // cout << "Node with value " << value << " deleted." << endl;
            return;
        }
        // Move to the next pair of nodes
        prevNode = currNode;
        currNode = currNode->next;
    }

    // If no node is found with the given value
    cout << "\n\tNode with value " << value << " not found in the list.\n"
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
    cout << "\nAll nodes freed." << endl;
}