#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BST
{
private:
    Node *root;

public:
    BST() : root(nullptr) {}
    //! Delete
    void deleteBST(Node *root)
    {
        if (!root)
            return;
        deleteBST(root->left);
        deleteBST(root->right);
        delete root;
    }
    ~BST()
    {
        deleteBST(root);
    }
    //! Traversal
    void preorderTraversal(Node *root)
    {
        if (!root)
        {
            return;
        }
        // Do something
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    void inorderTraversal(Node *root)
    {
        if (!root)
        {
            return;
        }
        inorderTraversal(root->left);
        // Do something
        inorderTraversal(root->right);
    }
    void postorderTraversal(Node *root)
    {
        if (!root)
        {
            return;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        // Do something
    }
    //! Find min
    Node *findMinRecursion(Node *root)
    {
        if (!root->left)
            return root;
        return findMinRecursion(root->left);
    }
    Node *findMin()
    {
        return findMinRecursion(root);
    }
    //! Find max
    Node *findMaxRecursion(Node *root)
    {
        if (!root->right)
            return root;
        return findMaxRecursion(root->right);
    }
    Node *findMax()
    {
        return findMaxRecursion(root);
    }
    //! insert
    Node *insertRecursion(Node *root, int value)
    {
        if (!root)
        {
            return new Node(value);
        }
        if (value < root->data)
            root->left = insertRecursion(root->left, value);
        if (value > root->data)
            root->right = insertRecursion(root->left, value);
        return root;
    }
    Node *insert(int value)
    {
        root = insertRecursion(root, value);
    }
    //! The number of node
    int countNodes(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);
        return 1 + leftCount + rightCount;
    }
    int countNodes()
    {
        return countNodes(root);
    }
    //! Height
    int nodeHeight(Node *root)
    {
        if (!root)
            return 0;
        return 1 + max(nodeHeight(root->left), nodeHeight(root->right));
    }
    int height(Node *targetNode)
    {
        return nodeHeight(targetNode);
    }
    //! Depth
    int nodeDepth(Node *root, Node *target, int depth = 0)
    {
        if (!root)
            return 0;
        if (root == target)
            return depth;
        int leftDepth = nodeDepth(root->left, target, depth + 1);
        int rightDepth = nodeDepth(root->right, target, depth + 1);
        if (leftDepth != 0)
            return leftDepth;
        if (rightDepth != 0)
            return rightDepth;
        return -1;
    }
    int depth(Node *targetNode)
    {
        return nodeDepth(root, targetNode, 0);
    }
    int maxDepth()
    {
        return height(root);
    }
};