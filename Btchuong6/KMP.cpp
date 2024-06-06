#include <iostream>
#include <string>
#include <vector>
using namespace std;

void initNext(string &P, vector<int> &next)
{
    next.resize(P.size(), 0);
    int j, k;
    for (j = 2; j < P.size(); j++)
    {
        k = j - 1;
        do
        {
            while (k > 0 && P[k] == P[j])
                k--;
            if (k > 0)
            {
                int i = 1;
                while (i <= k && P[i] == P[j])
                    i++;
                if (i > k)
                {
                    next[j] = k;
                    break;
                }
            }
            k--;
        } while (k > 0);
    }
}
int KMPsearch(string &text, string &pattern)
{
    int pSize = pattern.size();
    int tSize = text.size();
    if (text.size() < pattern.size())
    {
        cout << "Invalid text size" << endl;
        return -1;
    }
    vector<int> next;
    initNext(pattern, next);
    int i = 0, j = 0;
    do
    {
        for (; j < pSize && text[i] == pattern[i]; i++)
            j++;
        if (i <= tSize - pSize && j < pSize)
        {
            j = (j == 0) ? i++ : next[j];
        }
    } while (i <= tSize - pSize);
    return (j == pSize) ? (i - pSize) : -1;
}
int main()
{
    string V = "abdcababdcabdcb";
    string p = "bdcabdcb";
    cout << KMPsearch(V, p);
    return 0;
}