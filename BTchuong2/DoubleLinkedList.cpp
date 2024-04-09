#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class DoubleLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    // Constructor to create a new double linked list
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}
    // Destructor to destroy a list
    ~DoubleLinkedList()
    {
        while (head)
        {
            Node *curr = head;
            head = head->next;
            delete curr;
        }
    }
    // Check if the list is empty
    bool isEmpty()
    {
        return head == nullptr && tail == nullptr;
    }
    // get the size of the list
    // Complexity: O(n)
    int size()
    {
        int count = 0;
        Node *curr = head;
        while (curr->next)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }
    // Print All Nodes
    void printAll()
    {
        if (isEmpty())
        {
            cout << "There is no element in the queue" << endl;
            return;
        }
        int index = 1;
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << "Element " << index - 1 << ":\tvalue: " << curr->data << endl;
            curr = curr->next;
            index++;
        }
    }
    // Insert element at the front of the list
    void insertFront(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
            head = tail = newNode;
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    // Insert element at the back of the list
    void insertBack(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void find_and_insert_after(int value, int newValue)
    {
        if (isEmpty())
        {
            cout << "There is no node in the list";
            return;
        }
        Node *forward = head;
        Node *backward = tail;
        if (forward == backward && forward->data == value)
        {
            insertBack(newValue);
            return;
        }
        while (forward != backward && forward->prev != backward)
        {
            if (forward->data == value)
            {
                Node *newNode = new Node(newValue);
                newNode->next = forward->next;
                newNode->prev = forward;
                if (!forward->next->prev)
                    forward->next->prev = newNode;
                forward->next = newNode;
                return;
            }
            if (backward->data == value)
            {
                Node *newNode = new Node(newValue);
                newNode->next = backward->next;
                newNode->prev = backward;
                if (backward->next)
                    backward->next->prev = newNode;
                backward->next = newNode;
                return;
            }
            forward = forward->next;
            backward = backward->prev;
        }
        cout << "404: Not found" << endl;
    }
    void find_and_insert_before(int value, int newValue)
    {
        if (isEmpty())
        {
            cout << "There is no node in the list";
            return;
        }
        Node *forward = head;
        Node *backward = tail;
        if (head->data == value)
        {
            insertFront(newValue);
            return;
        }
        while (forward != backward && forward->prev != backward)
        {
            if (forward->data == value)
            {
                Node *newNode = new Node(newValue);
                newNode->next = forward;
                newNode->prev = forward->prev;
                if (forward->prev)
                    forward->prev->next = newNode;
                forward->prev = newNode;
                return;
            }
            if (backward->data == value)
            {
                Node *newNode = new Node(newValue);
                newNode->next = backward;
                newNode->prev = backward->prev;
                backward->prev->next = newNode;
                backward->prev = newNode;
                return;
            }
            forward = forward->next;
            backward = backward->prev;
        }
        cout << "404: Not found" << endl;
    }
    void deleteAll()
    {
        while (head)
        {
            Node *curr = head;
            head = head->next;
            delete curr;
        }
    }
    void deleteFront()
    {
        if (isEmpty())
            return;
        Node *curr = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete curr;
    }
    void deleteBack()
    {
        if (isEmpty())
            return;
        Node *curr = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete curr;
    }
    void deleteAt(int index)
    {
        if (isEmpty())
        {
            cout << "There is no element in the list" << endl;
            return;
        }
        if (index == 0)
        {
            deleteFront();
            return;
        }
        if (index == size())
        {
            deleteBack();
            return;
        }
        if (index < size() / 2)
        {
            Node *curr = head;
            for (int i = 0; i < index; i++)
                curr = curr->next;
            Node *temp = curr;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete temp;
            return;
        }
        else
        {
            Node *curr = tail;
            for (int i = size(); i > index; i--)
                curr = curr->prev;
            Node *temp = curr;
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
            delete temp;
            return;
        }
    }
};
int main()
{
    DoubleLinkedList myList;
    for (int i = 0; i < 5; i++)
    {
        myList.insertBack(i);
    }
    myList.find_and_insert_after(4, 20);
    myList.find_and_insert_before(0, 20);
    myList.deleteAt(2);
    myList.printAll();
    return 0;
}