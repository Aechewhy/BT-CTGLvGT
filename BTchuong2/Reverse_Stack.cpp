#include <iostream>
#include <cstdlib>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T value) : data(value), next(nullptr) {}
};
template <typename T>
class Stack
{
private:
    Node<T> *head;

public:
    Stack() : head(nullptr) {}
    ~Stack()
    {
        while (head)
        {
            Node<T> *curr = head;
            head = head->next;
            delete curr;
        }
    }
    void push(int value)
    {
        Node<T> *newNode = new Node<T>(value);
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
            Node<T> *curr = head;
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
        Node<T> *curr = head;
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
        Node<T> *prev = nullptr;
        Node<T> *curr = head;
        while (curr)
        {
            Node<T> *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    Node *getHead() const
    {
        return head;
    }
    void setHead(Node *newHead)
    {
        head = newHead;
    }
    friend Node<T> *Reverse(Node<T> *head);
};
template <typename T>
Node<T> *Reverse(Node<T> *head)
{
    if (!head)
    {
        cout << "There is no element in the list" << endl;
        return;
    }
    if (!head->next)
        return head;
    Node<T> *nextNode = head->next;
    if (!nextNode->next)
    {

        head->next = nullptr;
        nextNode->next = head;
        head = nextNode;
    }
    Node<T> *newHead = Reverse(nextNode);
    head->next = nullptr;
    nextNode->next = head;
    return newHead;
}
int main()
{
    Stack<int> stk;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    stk.insertElements(n);
    cout << "Your stack: " << endl;
    stk.printAll();
    Node *newhead = Reverse(stk.getHead());
    stk.setHead();
    cout << "Stack after reversing:" << endl;
    stk.printAll();
    return 0;
}