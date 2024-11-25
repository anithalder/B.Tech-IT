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
void createList(Node *&head);
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
    createList(first);
    cout << "Creating the second list...." << endl;
    createList(second);

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
    displayList(sum);

    // Free memory
    freeList(first);
    freeList(second);
    freeList(sum);

    cout << "\nExiting...\n";

    return 0;
}

// Function to create a linked list
void createList(Node *&head)
{
    // Hardcoding the first list (2 -> 4 -> 3 -> NULL)
    if (!head)
    {
        head = new Node(2);
        Node *tail = head;
        tail->next = new Node(4);
        tail = tail->next;
        tail->next = new Node(3);
    }
    else
    {
        // Hardcoding the second list (5 -> 6 -> 7 -> NULL)
        head = new Node(5);
        Node *tail = head;
        tail->next = new Node(6);
        tail = tail->next;
        tail->next = new Node(7);
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
    // cout << "All nodes freed." << endl;
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

    while (first != NULL || second != NULL || carry != 0)
    {
        int sum = carry;

        if (first != NULL && second != NULL)
        {
            sum = first->data + second->data;
            // sum += second->data;
            first = first->next;
            second = second->next;
        }

        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }

    while (first != NULL)
    {
        int sum = carry;

        if (first != NULL)
        {
            sum += first->data;
            first = first->next;
        }

        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }

    while (second != NULL)
    {
        int sum = carry;

        if (second != NULL)
        {
            sum += second->data;
            second = second->next;
        }

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
