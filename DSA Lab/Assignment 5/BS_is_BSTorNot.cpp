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

void createTree();
Node *createNode(int);
void freeTree(Node *root);
void printTree(Node *, int);
bool isBST(Node *);

int main()
{
    createTree(); // Initialize the BST with some predefined values.
    printTree(root, 0);
    if (isBST(root))
        cout << "\n\nThe tree is a Binary Search Tree.\n";
    else
        cout << "\n\nThe tree is not a Binary Search Tree.\n";
    return 0;
}

bool isBST(Node *root)
{
    if (root == NULL)
        return true;

    if (sizeof(root) > 3)
        return false;

    if (root->left != NULL && root->left->data > root->data)
        return false;

    if (root->right != NULL && root->right->data < root->data)
        return false;

    if (!isBST(root->left) || !isBST(root->right))
        return false;

    return true;
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
void createTree()
{
    root = NULL; // Reset root for initialization

    root = createNode(1);
    Node *node1 = createNode(2);
    Node *node2 = createNode(3);
    Node *node3 = createNode(4);
    Node *node4 = createNode(5);
    Node *node5 = createNode(6);
    Node *node6 = createNode(7);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
}
