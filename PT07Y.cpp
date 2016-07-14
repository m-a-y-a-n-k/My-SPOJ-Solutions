#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#define NO 0
#define YES 1

void DFS(int s,int &time,int *visit,int *d,int *parent,vector <int> G[] )
{
    visit[s] = YES;
    d[s] = time;
    vector <int> :: iterator it;
    it = G[s].begin();
    while( it != G[s].end() )
    {
        if( visit[*it] == YES )
        {
            if( d[s] > d[*it] && parent[s] != *it )
            {
                cout<<"NO"<<endl;
                exit(0);
            }
        }
        else
        {
            parent[*it]=s;
            ++time;
            DFS( *it , time , visit , d , parent, G );
        }
        it++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int V,E,a,b,i;
    cin>>V>>E;
    int visit[V],d[V],parent[V];
    vector <int> G[V];

    for(i=0;i<V;i++)
    {
        visit[i]=NO;
        d[i]=10000000;
        parent[i]=-1;
    }

    for(i=0;i<E;i++)
    {
        cin>>a>>b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    b=1;
    DFS(0,b,visit,d,parent,G);
    for(i=0;i<V;i++)
    {
        if(visit[i]==NO)
        {
            cout<<"NO"<<endl;
            exit(0);
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
