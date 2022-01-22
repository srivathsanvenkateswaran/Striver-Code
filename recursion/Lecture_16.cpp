#include <bits/stdc++.h>
using namespace std;
// M Coloring Problem 
// https://youtu.be/wuVwUK25Rfc?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

bool isSafe(int node, int color[], vector<int> graph[], int n, int colour)
{
    for(int i=0; i<graph[node].size(); i++)
    {
        if(color[graph[node][i]] == colour) return false;
    }
    return true;
}

bool MColoring(vector<int> graph[], int node, int m, int n, int color[])
{
    if(node == n) return true;

    for(int i=1; i<=m; i++)
    {
        if(isSafe(node, color, graph, n, i))
        {
            color[node] = i;
            if(MColoring(graph, node+1, m, n, color)) return true;
            color[node] = 0;
            // Backtracking step 
        }
    }

    return false;
}

int main()
{
    int n=4;
    vector<int> graph[n];

    graph[0].push_back(1);
    graph[1].push_back(0);
    
    graph[1].push_back(2);
    graph[2].push_back(1);
    
    graph[2].push_back(3);
    graph[3].push_back(2);
    
    graph[3].push_back(0);
    graph[0].push_back(3);
    
    graph[0].push_back(2);
    graph[2].push_back(0);

    int color[n] = {0};

    cout << MColoring(graph, 0, 3, n, color) << '\n';

    return 0;
}