#include <iostream>
#include <vector>

using namespace std;

typedef long long i64;

#define MAX 1000000

vector <int> childs[MAX+1];

bool visited[MAX+1];
i64 ans;

i64 Volume( int root, int n )
{
    int c;
    //cout << "Visit " << root << endl;
    i64 sum = 0, it = 0, len = childs[root].size();

    while ( it <  len )
    {
        c = childs[root][it];
        //cout << c << " is connected to " << root << endl;
        if( visited[c] == false )
        {
            //cout << "Unvisted !!" << endl;
            visited[c] = true;
            sum += 1 + Volume(c,n);
        }
        it++;
    }
    //cout << root << ": Volume is " << sum << endl;
    ans += ++sum;
    return sum;
}

int main()
{
    int t,a,b,i,n;
    cin >> t;
    while( t-- )
    {
        cin >> n;
        for( i = 0; i < n; i++ )
        {
            visited[i] = false;
            childs[i].clear();
        }
        for( i = 1; i < n; i++ )
        {
            cin >> a >> b;
            childs[a].push_back(b);
            childs[b].push_back(a);
        }
        ans = 0;
        visited[0] = true;
        Volume(0,n);
        cout << ans << endl;
    }
    return 0;
}
