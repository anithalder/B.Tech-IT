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

void createBST();
Node *createNode(int);
void freeTree(Node *root);
void printTree(Node *, int);
void insertBST(Node *&, int);
Node *deleteNodeBST(Node *, int);
Node *inOrderPredecessor(Node *ptr);

int main()
{
    createBST(); // Initialize the BST with some predefined values.

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
            insertBST(root, value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNodeBST(root, value);
            break;
        case 0:
            freeTree(root);
            cout << "\nExiting...\n\n";
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

void insertBST(Node *&ptr, int value)
{
    if (ptr == NULL)
    {
        ptr = createNode(value);
        return;
    }

    if (value < ptr->data)
        insertBST(ptr->left, value);

    else if (value > ptr->data)
        insertBST(ptr->right, value);

    else
        cout << "\nDuplication is not allowed! " << value << " already exists.\n";
}

Node *deleteNodeBST(Node *ptr, int value)
{
    if (ptr == NULL)
    {
        cout << "Value " << value << " not found in the tree.\n";
        return NULL;
    }

    if (value < ptr->data)
    {
        ptr->left = deleteNodeBST(ptr->left, value);
    }
    else if (value > ptr->data)
    {
        ptr->right = deleteNodeBST(ptr->right, value);
    }
    else
    {
        // Node with one child or no child
        if (ptr->left == NULL)
        {
            Node *temp = ptr->right;
            delete ptr;
            return temp;
        }
        else if (ptr->right == NULL)
        {
            Node *temp = ptr->left;
            delete ptr;
            return temp;
        }

        // Node with two children
        Node *inPre = inOrderPredecessor(ptr);
        ptr->data = inPre->data;
        ptr->left = deleteNodeBST(ptr->left, inPre->data);
    }
    return ptr;
}

Node *inOrderPredecessor(Node *ptr)
{
    ptr = ptr->left;
    while (ptr->right != NULL)
        ptr = ptr->right;
    return ptr;
}

Node *createNode(int data)
{
    return new Node(data);
}

// Function to print the BST
void printTree(Node *root, int space = 0)
{
    if (root == nullptr)
        return;

    space += 5;

    printTree(root->right, space);

    cout << '\n';
    for (int i = 5; i < space; i++)
    {
        cout << ' ';
    }
    cout << root->data;

    printTree(root->left, space);
}

// Function to free all nodes in a binary tree
void freeTree(Node *root)
{
    if (root == nullptr)
        return;

    freeTree(root->left);
    freeTree(root->right);

    delete root;
}

// Function to create a predefined BST
void createBST()
{
    root = NULL; // Reset root for initialization

    insertBST(root, 8);
    insertBST(root, 3);
    insertBST(root, 10);
    insertBST(root, 1);
    insertBST(root, 6);
    insertBST(root, 14);
    insertBST(root, 4);
    insertBST(root, 7);
    insertBST(root, 13);
}
