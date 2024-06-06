#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class hashNode
{
public:
    int data;
    hashNode *next;

public:
    hashNode(int Data) : data(Data), next(nullptr) {}
};
class hashTable
{
    vector<hashNode *> table;

public:
    hashTable(int n)
    {
        table.resize(n, nullptr);
    }
    ~hashTable()
    {
        for (hashNode *head : table)
        {
            while (head)
            {
                hashNode *temp = head;
                head = head->next;
                delete temp;
            }
        }
    }
    int size()
    {
        return table.size();
    }
    int hash(int key)
    {
        return key % size();
    }
    void insert(int key)
    {
        int index = hash(key);
        hashNode *newNode = new hashNode(key);
        hashNode *head = table[index];
        newNode->next = head;
        table[index] = newNode;
    }
    bool search(int key)
    {
        int index = hash(key);
        hashNode *head = table[index];
        while (head)
        {
            if (head->data == key)
                return true;
            head = head->next;
        }
        return false;
    }
    void remove(int key)
    {
        int index = hash(key);
        hashNode *head = table[index];
        hashNode *prev = nullptr;
        while (head)
        {
            if (head->data == key)
            {
                prev ? prev->next = head->next : table[index] = head->next;
                delete head;
                return;
            }
            prev = head;
            head = head->next;
        }
        cout << "Can't find the value" << endl;
    }
    void printAll()
    {
        for (hashNode *key : table)
        {
            if (key)
            {
                hashNode *head = key;
                while (head)
                {
                    cout << "Key: " << head->data << "\t" << "Address: " << hash(head->data) << endl;
                    head = head->next;
                }
            }
        }
    }
    void printAllSort()
    {
        vector<int> allKeys;
        for (hashNode *head : table)
        {
            while (head)
            {
                allKeys.push_back(head->data);
                head = head->next;
            }
        }
        sort(allKeys.begin(), allKeys.end());
        for (int key : allKeys)
        {
            cout << "Key: " << key << endl;
        }
    }
};
int main()
{
    hashTable table(100);
    table.insert(123);
    table.insert(234);
    table.insert(345);
    table.insert(223);
    table.printAllSort();
    cout << table.search(123) << endl;
    table.remove(223);
    cout << table.search(223) << endl;
    table.printAll();
    return 0;
}
