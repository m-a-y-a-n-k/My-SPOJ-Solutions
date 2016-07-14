#include <iostream>
#include <set>
#include <vector>

using namespace std;

set <int> G[102],start;
set <int> :: iterator it;
vector <int> series;

int indegree[102]={0};

void Topological()
{
    int u;
    while(!start.empty())
    {
        u = *(start.begin());
        start.erase(start.begin());
        series.push_back(u);
        it = G[u].begin();
        while(it!=G[u].end())
        {
            if(--indegree[*it]==0)
                start.insert(*it);
            it++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int N,M,k,a,b;
    cin>>N>>M;
    for(;M--;)
    {
        cin>>a>>k;
        indegree[a]+=k;
        for(;k--;)
        {
            cin>>b;
            G[b].insert(a);
        }
    }
    for(a=1;a<=N;a++)
    {
        //cout<<a<<" has indegree "<<indegree[a]<<endl;
        if(indegree[a]==0)
            start.insert(a);
    }
    Topological();
    //cout<<"Serial Order:"<<endl;
    for(a=0;a<N;a++)
        cout<<series[a]<<" ";
    return 0;
}
