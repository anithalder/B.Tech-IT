#include <iostream>
using namespace std;

typedef struct Node
{
    Node *left, *right;
    int data;

    Node(int data)
    {
        this->left = NULL;
        this->data = data;
        this->right = NULL;
    }
} Node;

Node *root = NULL;

void printTree(Node *, int);
void createBST();
Node *createNode(int);
void freeTree(Node *root);
void insertNode(Node *, int);
void deleteNode(Node *, int);

int main()
{
    // createBST();
    while (1)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert Node in the tree\n";
        cout << "2. Delete Node from tree\n";
        cout << "0. Exit\n";
        printTree(root, 0);
        cout << "\nEnter your choice: ";
        int choice, value;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertNode(root, value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            deleteNode(value);
            break;
        case 0:
            freeTree(root);
            cout << "\nExiting...\n"
                 << endl;
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

void insertNode(Node *root, int value)
{
    if (root == NULL)
    {
        root = createNode(value);
        return;
    }

    while (root != NULL)
    {
        if (value == root->data)
        {
            return;
            cout << "\n\tDuplication is not allowed!\n\n";
        }
    }
}

void deleteNode(int value)
{
}

Node *createNode(int data)
{
    return new Node(data);
}

// Function to print the BST
void printTree(Node *root, int space = 0)
{
    // Base case: if the node is null, return
    if (root == nullptr)
        return;

    // Increase distance between levels
    space += 5;

    // Process right child first (to print it above the current node)
    printTree(root->right, space);

    // Print current node after space
    cout << '\n';
    for (int i = 5; i < space; i++)
    {
        cout << ' '; // Print spaces for indentation
    }
    cout << root->data; // Print the node's data

    // Process left child
    printTree(root->left, space);
}

// Function to free all nodes in a binary tree
void freeTree(Node *root)
{
    if (root == nullptr)
        return;

    // Recursively free the left and right subtrees
    freeTree(root->left);
    freeTree(root->right);

    // Delete the current node
    delete root;
}

// Let's consider the BST Look's like this
/*
              8
             / \
            3  10
           / \  \
          1  7  14
*/
/*
void createBST()
{
    // creating the nodes

    Node *node1 = createNode(8);
    Node *node2 = createNode(3);
    Node *node3 = createNode(10);
    Node *node4 = createNode(1);
    Node *node5 = createNode(7);
    Node *node6 = createNode(14);

    // creating the BST

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;

    // initialization of root

    root = node1;
}
*/