#include <iostream>
#include <cstring>

using namespace std;

void add(int p,int f,long long *FB,int N)
{
    int i;
    for(i=p;i<=N;i+=i&(-i))
    {
        FB[i]+=f;
    }
}

long long Find(int a,int b,long long *FB)
{
    int i;
    long long ans=0;
    for(i=b;i>0;i-=i&(-i))
    {
        ans+=FB[i];
    }
    for(i=a-1;i>0;i-=i&(-i))
    {
        ans-=FB[i];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int N,Q,a,b;
    cin>>N>>Q;
    long long FB[N+1];
    string op;
    memset(FB,0,sizeof(FB));
    while(Q--)
    {
        cin>>op;
        cin>>a>>b;
        if(op=="add")
        {
            add(a,b,FB,N);
        }
        else if(op=="find")
        {
            cout<<Find(a,b,FB)<<endl;
        }
    }
    return 0;
}
