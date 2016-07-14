#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int R,C,n,i,sx,sy,x,y;
    bool win;
    cin >> R >> C;
    int animal[3][R][C];

    cin>>n;

    while(n--)
    {
        for( i = 0; i < 3; i++ )
        {
            cin >> sx >> sy ;
            sx--;
            sy--;
            for( x = 0; x < R; x++ )
            {
                for( y = 0; y < C; y++)
                {
                    animal[i][x][y] = abs(x-sx) + abs(y-sy);
                }
            }
        }
        win = false;
        for( x = 0; x < R; x++ )
        {
            if( animal[1][x][0] > animal[0][x][0] && animal[2][x][0] > animal[0][x][0] )
            {
                win = true;
                break;
            }
            if( animal[1][x][C-1] > animal[0][x][C-1] && animal[2][x][C-1] > animal[0][x][C-1] )
            {
                win = true;
                break;
            }
        }
        if( win == true )
            cout << "YES" << endl;
        else
        {
            for( y = 1; y < C-1; y++ )
            {
                if( animal[1][0][y] > animal[0][0][y] && animal[2][0][y] > animal[0][0][y] )
                {
                    win = true;
                    break;
                }
                if( animal[1][R-1][y] > animal[0][R-1][y] && animal[2][R-1][y] > animal[0][R-1][y] )
                {
                    win = true;
                    break;
                }
            }
            if( win == true )
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
