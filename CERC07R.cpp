#include <iostream>

using namespace std;

int main()
{
    int G,p[2],d[2],i;
    string name1,name2,call;
    bool over = false;
    for( G = 1; G > 0; G++ )
    {
        cin >> name1 >> name1 >> name2 >> name2;
        cout << "Game #" << G << ":\n";
        p[0] = p[1] = 0;
        while( 1 )
        {
            for( i = 0; i <= 1; i++ )
            {
                cin >> call;
                switch( call[0] )
                {
                    case 'R':
                            if( call[1] == 'e' )
                            {
                                d[i] = 2;
                                break;
                            }
                    case 'K':
                    case 'G':
                            d[i] = 0;
                            break;
                    case 'N':
                    case 'O':
                    case 'T':
                            d[i] = 1;
                            break;
                    case 'P':
                            if( call[1] == 'i' )
                                d[i] = 0;
                            else
                                d[i] = 2;
                            break;
                    case 'C':
                            if( call[1] == 'a' )
                                d[i] = 2;
                            else
                                d[i] = 1;
                            break;
                    case 'S':
                            if( call[1] == 'c' )
                                d[i] = 1;
                            else
                                d[i] = 0;
                            break;
                    case 'F':
                            if( call[1] == 'o' )
                                d[i] = 1;
                            if( call[1] == 'e' )
                                d[i] = 2;
                            break;
                }
                if( call == "." )
                {
                    over = true;
                    break;
                }
                if( call == "-" || call == "_")
                {
                    break;
                }
            }
            if( call == "." )
            {
                over = true;
                break;
            }
            if( call == "-" || call == "_")
            {
                break;
            }
            for( i = 0; i <= 1; i++ )
            {
                if( ( d[i] == 0 && d[(i+1)%2] == 1 ) || ( d[i] == 1 && d[(i+1)%2] == 2 ) || ( d[i] == 2 && d[(i+1)%2] == 0 ) )
                {
                    p[i]++;
                }
            }
        }

        call = "point";
        if( p[0] != 1 )
            call = call + "s";

        cout << name1 << ": " << p[0] << " " << call << endl;

        call = "point";
        if( p[1] != 1 )
            call = call + "s";

        cout << name2 << ": " << p[1] << " " << call << endl;

        if( p[0] == p[1] )
        {
                cout << "TIED GAME" << endl;
        }
        else
        {
                cout << "WINNER: ";
                if( p[0] < p[1] )
                {
                    cout << name2;
                }
                else if( p[1] < p[0] )
                {
                    cout << name1;
                }
                cout << endl;
        }

        if( over == true )
            break;
        else
            cout << endl;
    }
    return 0;
}
