#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N,K,i,fact[13],ans;
    fact[0]=1;
    for(i=1;i<=12;i++)
        fact[i]=fact[i-1]*i;
    while(cin>>N)
    {
        cin>>K;
        ans=fact[N];
        while(K--)
        {
            cin>>i;
            ans/=fact[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
