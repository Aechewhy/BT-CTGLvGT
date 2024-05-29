#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
    Node() : next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    LinkedList() : head(nullptr) {}
    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool empty()
    {
        return head == nullptr;
    }

    int size()
    {
        int i = 0;
        Node *curr = head;
        while (curr)
        {
            i++;
            curr = curr->next;
        }
        return i;
    }

    void addNode(int val)
    {
        if (head == nullptr)
        {
            head = new Node(val);
            return;
        }
        Node *curr = head;
        while (curr->next)
            curr = curr->next;
        curr->next = new Node(val);
    }

    void addNodes(std::vector<int> vals)
    {
        for (int val : vals)
        {
            addNode(val);
        }
    }

    void printAllNodes()
    {
        if (empty())
        {
            std::cout << "There is no node in the list" << std::endl;
            return;
        }
        Node *curr = head;
        while (curr)
        {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    void deleteAt(int pos)
    {
        if (pos < 0 || pos > size())
        {
            cout << "invalid position" << endl;
            return;
        }
        Node *curr = head;
        for (int i = 0; i < pos; i++)
        {
            curr = curr->next;
        };
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    void insertFront(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head->next;
        head->next = newNode;
    }
    int getNodeIndex(Node *node)
    {
        if (head)
            return -1;
        int count = 0;
        Node *curr = head;
        while (curr)
        {
            if (curr == node)
                return count;
            curr = curr->next;
        }
        cout << "No node in the list" << endl;
        return -1;
    }
    Node *getNodeAt(int pos)
    {
        if (pos < 0 || pos > size() || !head)
            return nullptr;
        Node *curr = head;
        for (int i = 0; i < pos; i++)
        {
            curr = curr->next;
        }
        return curr;
    }
};
#endif // LINKEDLIST_H
