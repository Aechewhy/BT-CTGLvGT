#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    int height;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};
class AVLTree
{
private:
    Node *root;

public:
    AVLTree() : root(nullptr) {}
    int getHeight(Node *node)
    {
        if (!node)
            return 0;
        return node->height;
    }
    int getBalanceFactor(Node *node)
    {
        if (!node)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    Node *leftRotation(Node *node)
    {
        if (!node->right)
            return node;
        Node *temp = node->right;
        node->right = temp->left;
        temp->left = node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));
        return temp;
    }
    Node *rightRotation(Node *node)
    {
        if (!node->left)
            return node;
        Node *temp = node->left;
        node->left = temp->right;
        temp->left = node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));
        return temp;
    }
    Node *insertNode(Node *node, int val)
    {
        if (!node)
            return new Node(val);
        if (val < node->data)
            node->left = insertNode(node->left, val);
        if (val > node->data)
            node->right = insertNode(node->right, val);
        else
            return node;
        node->height = max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);
        if (balance > 1)
        {
            if (val < node->left->data)
                rightRotation(node);
            else
            {
                leftRotation(node->left);
                rightRotation(node);
            }
        }
        if (balance < -1)
        {
            if (val > node->right->data)
                leftRotation(node);
            else
            {
                rightRotation(node->right);
                leftRotation(node);
            }
        }
    }
};