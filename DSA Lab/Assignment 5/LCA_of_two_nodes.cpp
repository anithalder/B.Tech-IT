#include <iostream>
using namespace std;

// Definition for a binary tree node.
typedef struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data, Node *left = NULL, Node *right = NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
} Node;

void printTree(Node *, int);
Node *createNode(int val);
Node *createTree();
Node *lowestCommonAncestor(Node *root, Node *p, Node *q);
Node *root = createTree();

int main()
{
    printTree(root, 0);
    Node *p = root->left->left;
    Node *q = root->left->right->right;
    Node *lca = lowestCommonAncestor(root, p, q);
    cout << "\n\nThe lowest common ancestor of " << p->data << " and "
         << q->data << " is " << lca->data
         << endl;
    return 0;
}

// Function to find the LCA of two nodes in a binary tree
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL || root == p || root == q)
        return root;

    Node *left = lowestCommonAncestor(root->left, p, q);
    Node *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}

Node *createNode(int val)
{
    return new Node(val, NULL, NULL);
}

Node *createTree()
{
    Node *root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->right->left = createNode(0);
    root->right->right = createNode(8);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);
    return root;
}

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