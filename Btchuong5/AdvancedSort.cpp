#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class LinkedList
{
    Node *head;
    Node *tail;
};