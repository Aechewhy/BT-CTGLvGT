#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
struct Components
{
    double coefficients;
    int exponents;
    Components() : coefficients(0), exponents(0) {}
    Components(double coeff, int exp) : coefficients(coeff), exponents(exp) {}
};
struct Node
{
    Components comp;
    Node *next;
    Node() : next(nullptr) {}
    Node(Components Comp) : comp(Comp), next(nullptr) {}
};
class Polynomial
{
private:
    Node *head;

public:
    Polynomial() : head(nullptr) {}
    ~Polynomial()
    {
        while (head)
        {
            Node *curr = head;
            head = head->next;
            delete curr;
        }
    }
    void printPolynomial()
    {
        if (head == nullptr)
        {
            cout << "Polynomial is empty." << endl;
            return;
        }

        Node *curr = head;
        while (curr)
        {
            if (curr->comp.coefficients != 0)
            {
                if (curr->comp.coefficients > 0)
                {
                    if (curr != head)
                        cout << " + ";
                    if (curr->comp.coefficients != 1)
                        cout << curr->comp.coefficients;
                }
                else
                {
                    if (curr->comp.coefficients != -1)
                        cout << curr->comp.coefficients;
                    else
                        cout << "-";
                }
                if (curr->comp.exponents > 0)
                {
                    cout << "x";
                    if (curr->comp.exponents > 1)
                        cout << "^" << curr->comp.exponents;
                }
                else if (curr->comp.exponents == 0)
                {
                    if (curr->comp.coefficients == 1 || curr->comp.coefficients == -1)
                        cout << "1";
                }
            }
            curr = curr->next;
        }
    }
    void append(Components &comp)
    {
        Node *newNode = new Node(comp);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = newNode;
    }
    void append(double coeff, int exp)
    {
        Components comp(coeff, exp);
        append(comp);
    }
    void createPoly(vector<Components> comps)
    {
        for (int i = 0; i < comps.size(); i++)
        {
            append(comps[i]);
        }
    }
    Node *sortTermsByExponentsDescending()
    {
        Node *current = head;
        Node *sortedHead = nullptr;
        while (current != nullptr)
        {
            Node *prev = nullptr;
            Node *maxNode = current;
            while (current->next != nullptr)
            {
                if (current->next->comp.exponents > maxNode->comp.exponents)
                {
                    prev = current;
                    maxNode = current->next;
                }
                current = current->next;
            }
            if (prev != nullptr)
            {
                prev->next = maxNode->next;
            }
            else
            {
                head = maxNode->next;
            }
            maxNode->next = sortedHead;
            sortedHead = maxNode;
            current = head;
        }
        return sortedHead;
    }
};
vector<Components> parseEquation(string equation)
{
    vector<Components> polynomial;
    stringstream ss(equation);
    string Component;
    char op = '+';
    while (getline(ss, Component, '+') || getline(ss, Component, '-'))
    {
        if (!ss.eof())
        {
            op = equation[ss.tellg()];
        }
        Components temp;
        stringstream comp_ss(Component);
        if (Component.find("x^") != string::npos)
        {
            size_t pos = Component.find("x^");
            temp.coefficients = stod(Component.substr(0, pos));
            temp.exponents = stod(Component.substr(pos + 2));
        }
        else if (Component.find("x") != string::npos)
        {
            size_t pos = Component.find("x");
            temp.coefficients = stod(Component.substr(0, pos));
            temp.exponents = 1.0;
        }
        else
        {
            temp.coefficients = stod(Component);
            temp.exponents = 0.0;
        }
        if (op == '-')
        {
            temp.coefficients = -temp.coefficients;
        }
        polynomial.push_back(temp);
    }
    return polynomial;
}
Polynomial addPolynomials(Polynomial p1, Polynomial p2)
{
    Polynomial result;
    Node *curr1 = p1.sortTermsByExponentsDescending();
    Node *curr2 = p2.sortTermsByExponentsDescending();
    while (curr1 != nullptr && curr2 != nullptr)
    {
        if (curr1->comp.exponents == curr2->comp.exponents)
        {
            result.append(curr1->comp.coefficients + curr2->comp.coefficients, curr1->comp.exponents);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else if (curr1->comp.exponents > curr2->comp.exponents)
        {
            result.append(curr1->comp.coefficients, curr1->comp.exponents);
            curr1 = curr1->next;
        }
        else
        {
            result.append(curr2->comp.coefficients, curr2->comp.exponents);
            curr2 = curr2->next;
        }
    }
    while (curr1 != nullptr)
    {
        result.append(curr1->comp.coefficients, curr1->comp.exponents);
        curr1 = curr1->next;
    }
    while (curr2 != nullptr)
    {
        result.append(curr2->comp.coefficients, curr2->comp.exponents);
        curr2 = curr2->next;
    }
    return result;
}
void GeneratePoly(Polynomial &p)
{
    int exp;
    cout << "Enter the biggest exponent: " << endl;
    cin >> exp;
    cout << "Enter coefficients: " << endl;
    for (int i = 0; i <= exp; i++)
    {
        double coeff;
        cout << "x^" << i << ":";
        cin >> coeff;
        p.append(coeff, i);
    }
}
int main()
{
    Polynomial p1;
    Polynomial p2;
    GeneratePoly(p1);
    cout << "First polynomial: ";
    p1.printPolynomial();
    cout << endl;
    GeneratePoly(p2);
    cout << "Second polynomial: ";
    p2.printPolynomial();
    cout << endl;
    Polynomial sum = addPolynomials(p1, p2);
    cout << endl
         << "Sum: ";
    sum.printPolynomial();
    return 0;
}