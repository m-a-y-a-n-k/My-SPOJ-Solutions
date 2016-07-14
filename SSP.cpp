#include <bits/stdc++.h>

using namespace std;

#define Vertices 100
int INF = 99999999;
#define NIL 0

vector < pair<int,int> > Graph[Vertices+1];

priority_queue <int> pq;

void Relax(int u , int v, int w, int* distance) {
    if( distance[v] > distance[u] + w ){
        distance[v] = distance[u] + w;
    }
}

void initialise(int source, int *distance, int* parent)
{
    for( int i = 1; i <= Vertices; i++ ) {
        distance[i] = INF;
        parent[i] = NIL;
    }
    distance[source] = 0;
}

void djikstra(int source, int* distance, int* parent)
{
    initialise(source,distance,parent);
    vector < pair< int,int> > :: iterator it;
    pq.push(source);
    int u,v;
    while( !pq.empty() ) {
        u = pq.top();
        pq.pop();
        for( it = Graph[u].begin(); it != Graph[u].end(); it++ ) {
            Relax(u,(*it).first,(*it).second,distance);
            pq.push((*it).first);
        }
    }
}

int main()
{
    int distance[Vertices+1],parent[Vertices+1];
    int V,E,start,ends,weight;
    cout << "Enter number of vertex" << endl;
    cin >> V;
    cout << "Enter number of edges" << endl;
    cin >> E;
    cout << "Enter edges and weights" << endl;
    for( int i = 1; i <= E; i++ )
    {
        cout << "Enter start vertex" << endl;
        cin >> start;
        cout << "Enter end vertex" << endl;
        cin >> ends;
        cout << "Enter weight of edge" << endl;
        cin >> weight;
        Graph[start].push_back(make_pair(ends,weight));
    }
    djikstra(1,distance, parent);
    cout << "Shortest Distance " << endl;
    for( int i = 1; i <= V; i++ ) {
        cout << "To vertex " << i << " is : " << distance[i] << endl;
    }
    return 0;
}
