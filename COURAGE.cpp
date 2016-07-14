#include <iostream>
#include <cstdlib>

using namespace std;

#define INF 1e18
typedef long long LL;

struct SEGTREE
{
    int u,v;
    LL S,M;
    SEGTREE *left,*right;
};

SEGTREE* MAKE( SEGTREE *root, int u, int v, LL *apples )
{
    root = (SEGTREE*)malloc(sizeof(SEGTREE));
    root -> u = u;
    root -> v = v;
    root -> left = NULL;
    root -> right = NULL;

    if( u == v )
    {
        root -> S = root -> M = apples[u];
        return root;
    }

    root -> left = MAKE( root->left, u, (u+v)>>1, apples);
    root -> right = MAKE( root->right, ((u+v)>>1) + 1, v, apples);

    root -> S = root -> left -> S + root -> right -> S;
    root -> M = min( root -> left -> M , root -> right -> M );

    return root;
}

void UPDATE( int y, LL x, SEGTREE *root )
{
    if( root -> u <= y && y <= root -> v )
    {
        if( root -> u == root -> v )
        {
            root -> S = root -> M = x;
        }
        else
        {
            UPDATE( y, x, root -> left );
            UPDATE( y, x, root -> right );

            root -> S = root -> left -> S + root -> right -> S;
            root -> M = min( root -> left -> M, root -> right -> M );
        }
    }
}

void QUERY( SEGTREE *root, int a, int b, LL& ans_sum, LL& ans_min  )
{
    if( root -> v < a || b < root -> u )
    {
        return ;
    }
    if( root -> u >= a && root -> v <= b )
    {
        ans_sum = ans_sum + root -> S;
        if( ans_min > root -> M )
        {
            ans_min = root -> M;
        }
    }
    else
    {
        QUERY( root -> left, a, b, ans_sum, ans_min );
        QUERY( root -> right, a, b, ans_sum, ans_min );
    }
}

int main()
{
    SEGTREE *root = NULL;
    int n,p,a,b;
    string option;
    cin>>n;
    LL apples[n],Sum,Min;

    for(int i=0;i<n;i++)
    {
        cin>>apples[i];
    }

    cin>>p;
    root = MAKE( root, 0, n-1, apples );

    while(p--)
    {
        cin>>option;
        cin>>a>>b;
        if( option == "COUNT" )
        {
            Sum=0;
            Min=INF;
            QUERY( root, a, b, Sum, Min );
            cout<<Sum-Min<<endl;
        }
        else if( option == "EAT" )
        {
            apples[b] = apples[b] - a;
            UPDATE( b, apples[b], root );
        }
        else if( option == "GROW" )
        {
            apples[b] = apples[b] + a;
            UPDATE( b, apples[b], root );
        }
    }
    return 0;
}
