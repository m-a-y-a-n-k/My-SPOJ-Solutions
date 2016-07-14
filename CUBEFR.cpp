#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

int T,n,i,j,pos[MAX+1];
bool sp[MAX+1];

int main()
{
    ios_base::sync_with_stdio(false);
    memset(pos,-1,sizeof(pos));
    memset(sp,false,sizeof(sp));
    sp[0]=true;sp[1]=false;                             // true means a cube number
    cin>>T;
    for(i=2;i*i*i<=MAX;i++)
    {
        if(sp[i]==false)
        {
            for(j=i*i*i;j<=MAX;j+=i*i*i)
            {
                sp[j]=true;
            }
        }
    }
    j=1;
    for(i=1;i<=MAX;i++)
    {
        if(sp[i]==false)
        {
            pos[i]=j++;
        }
    }
    for(i=1;i<=T;i++)
    {
        cin>>n;
        cout<<"Case "<<i<<": ";
        if(sp[n]==true)
        {
            cout<<"Not Cube Free";
        }
        else
        {
            cout<<pos[n];
        }
        cout<<endl;
    }
    return 0;
}
