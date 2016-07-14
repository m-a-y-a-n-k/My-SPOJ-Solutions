#include <bits/stdc++.h>

using namespace std;

typedef struct SEG_TREE_node
{
    int u,v;
    long long L,S,M,R;
    SEG_TREE_node *left,*right;
}node;

#define LIMIT -1000000000

node* create( node* root ,int a ,int b ,int* data )
{
    root = (node*)malloc(sizeof(node));
    root -> left = root -> right = NULL;
    root -> u = a;
    root -> v = b;
    if( a == b )
    {
        root -> L = root -> S = root -> M = root -> R = data[a];
        return root;
    }
    root -> left = create( root -> left, a, (a+b)>>1, data );
    root -> right = create( root -> right, 1+((a+b)>>1), b, data );
    root -> S = root -> left -> S + root -> right -> S;
    root -> L = max( root -> left -> L, root -> left -> S + root -> right -> L) ;
    root -> R = max( root -> right -> R, root -> right -> S + root -> left -> R ) ;
    root -> M = max( root -> left -> M, max( root -> right -> M, max( root -> left -> R + root -> right -> L, max( root -> L, root -> R ) ) ) );
    return root;
}

void query( node* root, int a , int b, node* temp )
{
    if( root -> u > b || root -> v < a )
    {
        return ;
    }
    if( root -> u >= a && root -> v <= b )
    {
        temp -> S = temp -> S + root -> S;
        temp -> L = max( temp -> L, temp -> S + root -> L - root -> S );
        temp -> M = max( temp -> M, max( root -> M, max( temp -> R + root -> L, max( temp -> L, max( root -> R, root -> S + temp -> R ) ) ) ) );
        temp -> R = max( root -> R, root -> S + temp -> R );
        return;
    }
    query( root -> left, a, b, temp );
    query( root -> right, a, b, temp );
}

int main()
{
    int M,N,x,y;
    scanf("%d",&N);
    int* data = new int[N];
    for( x=0; x<N; x++ )
    {
        scanf("%d",&data[x]);
    }
    scanf("%d",&M);
    node *root = NULL;
    root = create( root, 0, N-1, data );
    node *res = (node*)malloc(sizeof(node));
    res -> left = res -> right = NULL;
    while(M--)
    {
        scanf("%d%d",&x,&y);
        res -> L = res -> R = res -> M = res -> S = LIMIT;
        query( root, x-1, y-1, res );
        printf("%lld\n",res->M);
    }
    return 0;
}
