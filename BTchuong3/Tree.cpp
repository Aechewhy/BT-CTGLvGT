#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *right, *left;
    Node(int value) : data(value), right(nullptr), left(nullptr) {}
};
class Tree
{
private:
    Node *root;

public:
    Tree() : root(nullptr) {}
    bool isEmpty()
    {
        return root->right && root->left;
    }
    int size(Node *root)
    {
        if (!root)
            return;
        return 1 + size(root->left) + size(root->right);
    }
    void printAll(Node *root)
    {
        if (!root)
            return;
        cout << root->data << endl;
    }
};