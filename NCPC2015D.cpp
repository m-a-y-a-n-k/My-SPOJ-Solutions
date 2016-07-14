#include <iostream>
#include <cstdio>

using namespace std;

#define MOD 1000000007
typedef long long _int;
_int p;

_int expo(int a,_int n)
{
    if( n == 0 )
        return 1;
    if( n == 1 )
        return a;

    p = expo(a,n/2)%MOD;

    if( n%2 == 0 )
    {
        return (p*p)%MOD;
    }

    return (a*p*p)%MOD;
}

int main()
{
    _int n,x,y;
    while(cin>>n)
    {
        for( y = n/3; y >= 0; y-- )
        {
            if( ( n - 3 * y ) % 2 == 0 )
                break;
        }
        x = ( n - 3 * y )/2;
        //cout<<"x = "<<x<<endl;
        //cout<<"y = "<<y<<endl;
        cout<<(expo(2,x)%MOD*expo(3,y)%MOD)%MOD<<endl;
    }
    return 0;
}
