#include <iostream>

using namespace std;

#define M 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    long long N,x,y,ans;
    cin>>T;
    while(T--)
    {
        cin>>N;

        x = N%M;
        y = ( x * x)%M;

        ans = ( ( (x + 6)*y )%M + ( 11*x + 6)%M )%M;

        ans = ( ans * 166666668 )%M;

        cout<<ans<<endl;

    }
    return 0;
}

