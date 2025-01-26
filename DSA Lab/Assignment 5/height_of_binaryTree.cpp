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

void createBinaryTree();
Node *createNode(int);
void freeTree(Node *root);
void printTree(Node *, int);
int heightCalculate(Node *);

int main()
{
    createBinaryTree(); // Initialize the BinaryTree with some predefined values.

    printTree(root, 0);

    cout << "\n\n"
         << "The height of the current tree is: " << heightCalculate(root)
         << "\n\n"
         << endl;

    return 0;
}

void insertBinaryTree(Node *&ptr, int value)
{
    if (ptr == NULL)
    {
        ptr = createNode(value);
        return;
    }

    if (value < ptr->data)
        insertBinaryTree(ptr->left, value);

    else if (value > ptr->data)
        insertBinaryTree(ptr->right, value);

    else
        cout << "\nDuplication is not allowed! " << value << " already exists.\n";
}

int heightCalculate(Node *root)
{
    if (root == NULL)
        return 0;

    int left_height = heightCalculate(root->left);
    int right_height = heightCalculate(root->right);

    return max(left_height, right_height) + 1;
}

Node *createNode(int data)
{
    return new Node(data);
}

// Function to print the BinaryTree
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

// Function to create a predefined BinaryTree
void createBinaryTree()
{
    root = NULL; // Reset root for initialization

    insertBinaryTree(root, 8);
    insertBinaryTree(root, 3);
    insertBinaryTree(root, 10);
    insertBinaryTree(root, 1);
    insertBinaryTree(root, 6);
    insertBinaryTree(root, 14);
    insertBinaryTree(root, 4);
    insertBinaryTree(root, 7);
    insertBinaryTree(root, 13);
}
