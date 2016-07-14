#include <vector>
#include <iostream>

using namespace std;

typedef long long _int;

#define MAX 5000001

bool prime[MAX],composite;
vector <int> primes;

int main()
{
    int i,j,T;
    long long N;
    for( i = 3; i*i < 2*MAX; i+=2 )
    {
        if( prime[i/2] == false )
        {
            for( j = i*i/2 ; j < MAX; j += i )
            {
                prime[j] = true;
            }
        }
    }
    primes.push_back(2);
    for( i = 1; i < MAX; i++ )
    {
        if( prime[i] == false )
        {
            primes.push_back( 2 * i + 1 );
        }
    }
    cin >> T;
    const int SIZE = primes.size();
    int t = T;
    while(T--)
    {
        cin >> N;
        composite = false;
        for( i = 0; i < SIZE; i++ )
        {
            if( N % primes[i] == 0 )
            {
                composite = true;
                break;
            }
        }
        cout << "Case #" << t - T << ": ";
        if( composite == false )
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ( N - primes[i] )/2 << endl;
        }
    }
    return 0;
}
