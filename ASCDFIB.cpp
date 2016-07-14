#include <bits/stdc++.h>

using namespace std;

#define RANGE 1100001
#define MOD 100000

int fib[RANGE];

int main()
{
    ios_base::sync_with_stdio(false);
    int T,i,j,A,B,x;
    cin>>T;
    fib[0]=1;
    fib[1]=0;
    fib[2]=1;
    for(i=3;i<=RANGE;i++)
    {
        fib[i]=(fib[i-1]+fib[i-2])%MOD;
    }
    for(i=1;i<=T;i++)
    {
        priority_queue <int> PQ;
        cin>>A>>B;
        cout<<"Case "<<i<<":";
        for(j=A;j<=(A+B);j++)
        {
            PQ.push(-fib[j]);
        }
        x=PQ.size();
        if(x>100)
        {
            x = 100;
        }
        while(x--)
        {
            cout<<" "<<-PQ.top();
            PQ.pop();
        }

        cout<<endl;
    }
    return 0;
}
