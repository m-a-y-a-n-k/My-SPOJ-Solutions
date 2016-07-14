#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int N, idx = 1, v, top;
    scanf( "%d" , &N );
    int place[N];
    vector < pair < int, int > > books;
    while( idx <= N )
    {
        scanf( "%d", &v );
        books.push_back( make_pair( v, idx++ ) );
    }
    sort( books.begin(), books.end() );
    top = N + 1;
    v = 0;
    for( idx = 1; idx < N; idx++ )
    {
        if( books[idx].second <= books[idx-1].second )
        {
            v = idx;
            break;
        }
    }
    printf("%d",N-v);
    return 0;
}
