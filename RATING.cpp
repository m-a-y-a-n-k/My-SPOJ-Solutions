#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

long long BIT[100001];
int i;

void add( int x )
{
    for( i = x ; i <= 100000; )
    {
        BIT[i]++;
        i = i + ( i & (-i) ) ;
    }
}

long long sum( int x )
{
    long long ans = 0;
    for( i = x; i >0; )
    {
        ans += BIT[i];
        i = i - (i & (-i));
    }
    return ans;
}

int main()
{
    int N,A,H;
    cin >> N;
    long long result[N];
    int i;
    pair < pair < int, int >, int> Coder[N];
    for( i = 0; i < N; i++ )
    {
        cin >> A >> H;
        Coder[i] = ( make_pair( make_pair( A, H ), i ) );
    }
    sort( Coder, Coder+N );

    add(Coder[0].first.second);
    result[Coder[0].second] = sum(Coder[0].first.second);
    for( i = 1 ; i < N; i++ )
    {
        if( Coder[i].first.first == Coder[i-1].first.first && Coder[i].first.second == Coder[i-1].first.second )
        {
            add(Coder[i].first.second);
            result[Coder[i].second] = result[Coder[i-1].second];
        }
        else
        {
            add(Coder[i].first.second);
            result[Coder[i].second] = sum(Coder[i].first.second);
        }
    }
    for( i = 0; i < N; i++ )
    {
        cout << result[i] - 1 << endl;
    }
    return 0;
}

