#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T value) : data(value), next(nullptr){};
};
template <typename T>
class Queue
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    Queue()
    {
        head = tail = nullptr;
    }
    ~Queue()
    {
        while (head)
        {
            Node<T> *curr = head;
            head = head->next;
            delete curr;
        }
    }
    bool isEmpty()
    {
        return head == nullptr && tail == nullptr;
    }
    friend ostream &operator<<(ostream &os, const Queue &queue)
    {
        if (queue.isEmpty())
        {
            os << "There is no element in the queue" << endl;
            return os;
        }
        int index = 1;
        Node<T> *curr = head;
        while (!curr)
        {
            os << "Element " << index << ":\tvalue: " << curr->data << endl;
            curr = curr->next;
            index++;
        }
        return os;
    }

    void printAll()
    {
        if (isEmpty())
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
    int size()
    {
        Node<T> *curr = head;
        int size = 0;
        while (curr != nullptr)
        {
            size++;
            curr = curr->next;
        }
        return size;
    }
    void enqueue(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (isEmpty())
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    int dequeue()
    {
        if (isEmpty())
            exit(-1);
        int value = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        return value;
    }
    void deleteItem(int index)
    {
        if (isEmpty() || index >= size())
        {
            cout << "Invalid index ";
            exit(-1);
        }
        if (index == 0)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node<T> *curr = head;
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }
        Node<T> *temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    void stringToWords(string str)
    {
        stringstream ss(str);
        string word;
        while (ss >> word)
        {
            enqueue(word);
        }
    }
};
typedef Queue<string> Words;
int main()
{
    Queue<string> String;
    cout << "Enter string: ";
    string s;
    getline(cin, s);
    String.stringToWords(s);
    cout << endl;
    cout << String;

    return 0;
}