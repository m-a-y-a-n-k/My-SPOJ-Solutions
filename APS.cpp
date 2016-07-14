#include <iostream>

using namespace std;

#define SIZE 5000000

// Store for only odd numbers- 1,3,5,7,9 with index 0,1,2,3,4

unsigned int val[SIZE];
unsigned long long ans[SIZE];
bool prime[SIZE];

int main()
{
    int t,i,j,n;
    cin >> t;
    for( i = 3; i*i <= 2*SIZE; i += 2 )
    {
        if( prime[i/2] == false )
        {
            val[i/2] = i;
            for( j = i*i; j <= 2*SIZE; j += 2*i )
            {
                if(val[j/2] == 0 )
                    val[j/2] = i;
                prime[j/2] = true;
            }
        }
    }
    for( i = 3; i <= 2*SIZE; i += 2 )
    {
        if( val[i/2] == 0)
            val[i/2] = i;
        ans[i/2] = ans[i/2-1] + val[i/2] + 2;
    }
    while(t--)
    {
        cin >> n;
        if( n == 0 )
            cout << 0 <<endl;
        else if( n%2 == 0 )
        {
            cout << ans[n/2-1] + 2 << endl;
        }
        else
        {
            cout << ans[n/2] << endl;
        }
    }
    return 0;
}
