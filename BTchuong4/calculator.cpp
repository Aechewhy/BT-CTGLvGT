#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node
{
    string component;
    Node *left;
    Node *right;
    Node(string c) : component(c), left(nullptr), right(nullptr) {}
};
class expressionTree
{
private:
    Node *root;

public:
    expressionTree() : root(nullptr) {}
    void insert(Node *&root, string val)
    {
        if (root == nullptr)
        {
            root = new Node(val);
        }
    }
    bool isOperator(string token)
    {
        return token == "+" || token == "-" || token == "*" || token == "/" || token == "%";
    }
};