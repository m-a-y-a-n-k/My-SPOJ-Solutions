#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int charf[2000];
int beg,last,n,max_size,counter,x;
char s[1000002];
char c;

int main()
{
    while( cin >> n && n > 0 )
    {
        cin.ignore();
        scanf( "%[^\n]s ", s );
        x = strlen(s);
        beg = last = max_size = counter = 0;
        memset( charf, 0, sizeof( charf ) );
        while( 1 )
        {
            //cout << beg << " " << last << " " << counter << " " << max_size << endl;
            if( counter == n || last == x )
            {
                max_size = max( max_size, last - beg );
                if( last == x )
                    break;
                do
                {
                    ;
                }while( --charf[s[beg++]] != 0 );
                counter--;
            }
            else
            {
                do
                {
                    charf[s[last++]]++;
                }while( charf[s[last]] != 0 );
                counter++;
            }
            if( beg > last )
                break;
        }
        cout << max_size << endl;
    }
    return 0;
}
