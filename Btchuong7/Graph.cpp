#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int>> graph;
vector<int> getAdjacentNodes(graph G, int node)
{
    vector<int> adjacentNodes;
    for (int i = 0; i < G.size(); i++)
    {
        adjacentNodes.push_back(G[node][i]);
    }
    return adjacentNodes;
}
bool cycleDetection(graph G, int start, int current)
{
    vector<int> adNodes = getAdjacentNodes(G, current);
    if (!adNodes.size())
        return false;
    else
    {
        for (int node : adNodes)
        {
            if (cycleDetection(G, start, node))
            {
                return true;
                break;
            }
        }
        return false;
    }
}

int main()
{

    return 0;
}