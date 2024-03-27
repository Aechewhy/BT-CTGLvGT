#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class Stack
{
private:
    Node *head;

public:
    Stack() : head(nullptr) {}
    ~Stack()
    {
        while (head)
        {
            Node *curr = head;
            head = head->next;
            delete curr;
        }
    }
    int size()
    {
        int count = 0;
        Node *curr = head;
        while (curr != nullptr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }
    void push(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    int pop()
    {
        if (!head)
        {
            cout << "There is no element in the stack" << endl;
            return -1;
        }
        else
        {
            Node *curr = head;
            head = head->next;
            int data = curr->data;
            delete curr;
            return data;
        }
    }
    void printAll()
    {
        if (!head)
        {
            cout << "There is no element in the queue" << endl;
            return;
        }
        int index = 1;
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << "Element " << index << ":\tvalue: " << curr->data << endl;
            curr = curr->next;
            index++;
        }
    }
    void insertElements(int number)
    {
        for (int i = 0; i < number; i++)
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            push(value);
        }
    }
    void reverseStack()
    {
        if (!head)
        {
            cout << "There is no element in the stack";
            return;
        }
        if (head->next == nullptr)
            return;
        Node *prev = nullptr;
        Node *curr = head;
        while (curr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void decimalToBinary(int dec)
    {
        Node *curr = head;
        while (dec > 0)
        {
            push(dec % 2);
            dec /= 2;
        }
    }
};
int main()
{
    Stack BinaryNumbers;
    BinaryNumbers.decimalToBinary(127);
    BinaryNumbers.printAll();
}