#include <iostream>
#include "Linkedlist.h"
#include "SA.h"
#include <random>
using namespace std;
vector<int> arrayGenerate(int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    std::vector<int> vals(n);
    for (int i = 0; i < n; ++i)
        vals[i] = dis(gen);
    return vals;
}
int main()
{
    LinkedList L;
    L.addNodes(arrayGenerate(7));
    cout << "Before sorting:" << endl;
    L.printAllNodes();
    cout << "After sorting:" << endl;
    heapSort(L);
    L.printAllNodes();
    return 0;
}