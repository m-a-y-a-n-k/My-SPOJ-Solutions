#include <bits/stdc++.h>

using namepsace std;

int V,E;
#define INF 99999999
#define NIL 0

set <pair<int,int>> Graph[V+1];
int distance[V+1];
priority_queue <int> pq;

void initialise(int source)
{
    for( int i = 1; i <= V; i++ ) {
        distance[i] = INF;
        parent[i] = NIL;
    }
    distance[source] = 0;
}

void djikstra()
{
    initialise();

}

int main()
{
    cout << "Enter number of vertices" << endl;
    cin >> V;
    cout << "Enter number of edges" << endl;
    cin >> E;
    cout << "Enter edges and weights" << endl;
    for( int i = 1; i <= E; i++ )
    {
        cout << "Enter start vertex" << endl;
        cin >> start;
        cout << "Enter end vertex" << endl;
        cin >> end;
        cin >> "Enter weight of edge" << endl;
        G[start].insert(make_pair(end,weight));
    }
    return 0;
}
