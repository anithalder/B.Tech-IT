#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

typedef struct node
{
    int data;
    node *next;
} node;
node *head = NULL;

node *createNode(int);
void insertNode(int);
void displayList();
void freeList();
void reverseList();

int main()
{
    int choice, value;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Reverse List\n";
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
            reverseList();
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

node *createNode(int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertNode(int data)
{
    node *p, *temp = createNode(data);
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
        cout << "\nList is empty!\n"
             << endl;
        return;
    }
    node *p = head;
    cout << "\n\tList is: ";
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << " NULL\n"
         << endl;
}

void reverseList()
{
    if (head == NULL || head->next == NULL)
        return;

    node *prevNode = head,
         *currNode = prevNode->next;

    while (currNode != NULL)
    {
        node *nextNode = currNode->next;
        currNode->next = prevNode;

        // Updated
        prevNode = currNode;
        currNode = nextNode;
    }

    head->next = NULL;
    head = prevNode;
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