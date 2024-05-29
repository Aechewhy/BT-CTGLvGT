#ifndef SORT_H
#define SORT_H
#include "Linkedlist.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>
using namespace std;
//! Selection sort
Node *findMinNode(Node *head)
{
    Node *min = head;
    Node *curr = head;
    while (curr)
    {
        min = (min->data > curr->data) ? curr : min;
        curr = curr->next;
    }
    return min;
}
void selectionSort(LinkedList &list)
{
    std::cout << "Selection sort: " << endl;
    Node *curr = list.head;
    while (curr->next != nullptr)
    {
        swap(findMinNode(curr)->data, curr->data);
        curr = curr->next;
        list.printAllNodes();
    }
}
//! Bubble sort
void bubbleSort(LinkedList &list)
{
    cout << "Bubble sort:" << endl;
    Node *curr = list.head;
    Node *prev = list.head;
    bool check = false;
    while (!check)
    {
        curr = list.head;
        prev = list.head;
        check = true;
        while (curr)
        {
            if (prev->data > curr->data)
            {
                swap(prev->data, curr->data);
                check = false;
            }
            prev = curr;
            curr = curr->next;
        }
        // list.printAllNodes();
    }
}
//! Insertion sort
void insertionSort(LinkedList &list)
{
    if (!list.head)
        return;
    Node *newHead = nullptr;
    while (list.head)
    {
        Node *curr = list.head;
        list.head = list.head->next;
        if (!newHead || newHead->data > curr->data)
        {
            curr->next = newHead;
            newHead = curr;
        }
        else
        {
            Node *temp = newHead;
            while (temp->next && temp->next->data < curr->data)
            {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
    }
    list.head = newHead;
}
//! Merge sort
void splitList(Node *head, Node *&a, Node *&b)
{
    if (!head || !head->next)
    {
        a = head;
        b = nullptr;
        return;
    }
    Node *fast = head->next;
    Node *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    a = head;
    b = slow->next;
    slow->next = nullptr;
}
Node *mergeLists(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    Node *newList = nullptr;
    if (a->data <= b->data)
    {
        newList = a;
        newList->next = mergeLists(a->next, b);
    }
    else
    {
        newList = b;
        newList->next = mergeLists(a, b->next);
    }
    return newList;
}
void mergeSort(Node *&head)
{
    if (!head || !head->next)
        return;
    Node *a;
    Node *b;
    splitList(head, a, b);
    if (a->next != nullptr)
        mergeSort(a);
    if (b->next != nullptr)
        mergeSort(b);
    head = mergeLists(a, b);
}
//! Quick sort
Node *LomutoPartition(Node *left, Node *right)
{
    int pv = right->data;
    Node *tracker = left;
    Node *scanner = left;
    while (scanner != right)
    {
        if (scanner->data < pv)
        {
            swap(tracker->data, scanner->data);
            tracker = tracker->next;
        }
        scanner = scanner->next;
    }
    swap(tracker->data, right->data);
    return tracker;
}
void sortQuickRange(Node *left, Node *right)
{
    if (left != right && left != right->next)
    {
        Node *pv = LomutoPartition(left, right);

        Node *prev = left;
        while (prev != nullptr && prev->next != pv)
        {
            prev = prev->next;
        }

        if (prev != nullptr)
        {
            sortQuickRange(left, prev);
        }
        sortQuickRange(pv->next, right);
    }
}

void quickSort(LinkedList &list)
{
    if (!list.head)
    {
        return;
    }
    Node *right = list.head;
    while (right->next)
    {
        right = right->next;
    }
    sortQuickRange(list.head, right);
}
//! Heap sort
void heapify(LinkedList &l, int i, int n)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    Node *smallestNode = l.getNodeAt(smallest);
    Node *leftNode = l.getNodeAt(left);
    Node *rightNode = l.getNodeAt(right);

    if (left < n && leftNode != nullptr && leftNode->data > smallestNode->data)
    {
        smallest = left;
        smallestNode = leftNode;
    }

    if (right < n && rightNode != nullptr && rightNode->data > smallestNode->data)
    {
        smallest = right;
        smallestNode = rightNode;
    }

    if (smallest != i)
    {
        Node *iNode = l.getNodeAt(i);
        std::swap(iNode->data, smallestNode->data);
        heapify(l, smallest, n);
    }
}
void heapSort(LinkedList &l)
{
    int n = l.size();
    // Build heap (rearrange linked list)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(l, i, n);
    }
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        Node *rootNode = l.getNodeAt(0);
        Node *endNode = l.getNodeAt(i);
        std::swap(rootNode->data, endNode->data);

        heapify(l, 0, i);
    }
}
#endif