#include <bits/stdc++.h>

using namespace std;
#define MAX 10000

bool mark[MAX+1]={false};

vector <int> List[MAX+1];
vector <int> :: iterator st;
long long ans[MAX+1]={1};
queue <int> q;
int save;

void solve(int src)
{
    q.push(src);
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        if(mark[s]==true)
        {
            continue;
        }
        mark[s]=true;
        st=List[s].begin();
        while(st!=List[s].end())
        {
            q.push(*st);
            save=*st;
            st++;
            ans[save]=ans[s]+1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int N,i,a,b;
    cin>>N;
    i=1;
    while(i<N)
    {
        cin>>a>>b;
        List[a-1].push_back(b-1);
        List[b-1].push_back(a-1);
        i++;
    }
    solve(0);
    ans[save]=1;
    memset(mark,false,sizeof(mark));
    solve(save);
    cout<<ans[save]-1<<endl;
    return 0;
}
