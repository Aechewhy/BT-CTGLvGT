#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class LinkedList
{
public:
    Node *head;

public:
    int size()
    {
        Node *curr = head;
        int count = 0;
        while (!curr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }
};
Node *Reverse(Node *head)
{
    if (!head)
    {
        cout << "There is no element in the list" << endl;
        return;
    }
    if (!head->next)
        return head;
    Node *nextNode = head->next;
    if (!nextNode->next)
    {

        head->next = nullptr;
        nextNode->next = head;
        head = nextNode;
    }
    Node *newHead = Reverse(nextNode);
    head->next = nullptr;
    nextNode->next = head;
    return newHead;
}
int main()
{
}
