#include <iostream>
#include <cstring>

using namespace std;

int compute( int *height, int a, int* parent )
{
    if( parent[a] == 0 )
        return height[a] = 1;

    if( height[parent[a]] != 0 )
        return height[a] = 1 + height[parent[a]];

    return height[a] = 1 + compute(height, parent[a], parent);
}

int LCA( int a, int b, int* parent, int* height )
{
    if( height[a] == height[b] )
    {
        if( a == b)
            return a;

        while( a != b )
        {
            a = parent[a];
            b = parent[b];
        }
        return a;
    }
    else if( height[a] > height[b] )
    {
        while( height[a] != height[b] )
        {
            a = parent[a];
        }
        return LCA( a, b, parent, height );
    }
    else
    {
        while( height[a] != height[b] )
        {
            b = parent[b];
        }
        return LCA( a, b, parent, height );
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t,T,x,N,n,y,Q;
    cin>>T;
    for( t=1; t<=T; t++ )
    {
        cin>>N;
        int parent[N+1],height[N+1];
        for( n = 0; n<=N; n++)
        {
            parent[n] = height[n] = 0;
        }
        for( n = 1; n<=N; n++ )
        {
            cin>>x;
            while(x--)
            {
                cin>>y;
                parent[y] = n;
            }
        }
        for( n = 1; n <= N ; n++ )
        {
            if( height[n] == 0 )
                height[n] = compute( height, n, parent );
        }
        cout<<"Case "<<t<<":"<<endl;
        cin>>Q;
        while(Q--)
        {
            cin>>x>>y;
            cout<<LCA( x, y, parent, height )<<endl;
        }
    }
    return 0;
}
