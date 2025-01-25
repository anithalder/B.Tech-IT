#include <iostream>
using namespace std;

// Node structure
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

// Function prototypes
void createList(Node *&head, int);
void displayList(Node *head);
void freeList(Node *head);
void insertAtTail(Node *&head, Node *&tail, int data);
Node *reverseList(Node *head);
Node *add(Node *first, Node *second);
Node *addTwoLists(Node *first, Node *second);

int main()
{
    Node *first = NULL, *second = NULL;

    // Create lists
    cout << '\n'
         << "Creating the first list...." << endl;
    createList(first, 345);
    cout << "Creating the second list...." << endl;
    createList(second, 45);

    // Display the lists
    cout << "\nFirst List: ";
    displayList(first);

    cout << "\nSecond List: ";
    displayList(second);
    cout << '\n';

    // Add the two lists
    Node *sum = addTwoLists(first, second);

    // Display the result
    cout << "Sum List: ";
    displayList(sum); // No need to reverse again here

    // Free memory
    freeList(first);
    freeList(second);
    freeList(sum);

    cout << "\nExiting...\n";

    return 0;
}

// Function to create a linked list from a number
void createList(Node *&head, int number)
{
    if (number == 0)
    {
        head = new Node(0); // Handle the case for 0
        return;
    }

    while (number > 0)
    {
        int digit = number % 10; // Extract the last digit
        Node *newNode = new Node(digit);

        newNode->next = head; // Insert at the beginning (most significant digit)
        head = newNode;       // Move the head to the new node

        number /= 10; // Remove the last digit
    }
}

// Function to display a linked list
void displayList(Node *head)
{
    if (!head)
    {
        cout << "Empty!\n";
        return;
    }

    Node *p = head;
    while (p != NULL)
    {
        cout << p->data;
        if (p->next != NULL)
            cout << "->";
        p = p->next;
    }
    cout << "->NULL\n";
}

// Function to free the memory of a linked list
void freeList(Node *head)
{
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to reverse a linked list
Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *prevNode = NULL, *currNode = head;

    while (currNode != NULL)
    {
        Node *nextNode = currNode->next; // Store the next node
        currNode->next = prevNode;       // Reverse the link
        prevNode = currNode;             // Move prevNode forward
        currNode = nextNode;             // Move currNode forward
    }

    return prevNode; // New head of the reversed list
}

// Function to add a node at the tail of a list
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

// Function to add two linked lists
Node *add(Node *first, Node *second)
{
    int carry = 0;
    Node *ansHead = NULL, *ansTail = NULL;

    while (first != NULL && second != NULL)
    {
        int sum = carry + first->data + second->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        first = first->next;
        second = second->next;
    }

    while (first != NULL)
    {
        int sum = carry + first->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        first = first->next;
    }
    while (second != NULL)
    {
        int sum = carry + second->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        second = second->next;
    }
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }

    return ansHead;
}

// Function to reverse the input lists, add them, and reverse the result
Node *addTwoLists(Node *first, Node *second)
{
    first = reverseList(first);
    second = reverseList(second);

    Node *result = add(first, second);

    // Reverse the result to maintain proper order
    return reverseList(result);
}
