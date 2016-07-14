#include <iostream>
#include <cstdlib>

using namespace std;

struct TREE
{
    int data;
    TREE *left,*right;
};

TREE *root = NULL,*temp = NULL;

void MAKE_TREE( int* PreOrder, int *Position, int lim )
{
    if( root == NULL )
    {
        root = ( TREE* )malloc( sizeof(TREE) );
        root -> left = NULL;
        root -> right = NULL;
        root -> data = PreOrder[0];
        temp = root;
    }

    int i=1;

    while( i!= lim )
    {
        if( Position[PreOrder[i]] < Position[temp->data] )
        {
            if( temp -> left == NULL )
            {
                temp -> left = (TREE *)malloc( sizeof(TREE) );
                temp = temp -> left;
                temp -> data = PreOrder[i++];
                temp -> left = NULL;
                temp -> right = NULL;
                temp = root;
            }
            else
                temp = temp -> left;
        }
        else
        {
            if( temp->right == NULL )
            {
                temp -> right = (TREE *)malloc( sizeof(TREE) );
                temp = temp -> right;
                temp -> data = PreOrder[i++];
                temp -> left = NULL;
                temp -> right = NULL;
                temp = root;
            }
            else
                temp = temp -> right;
        }
    }
}

int idx=0;
void CHECK( int *PostOrder , TREE *temp )
{
    if( temp == NULL )
        return ;

    CHECK( PostOrder, temp -> left );
    CHECK( PostOrder, temp -> right );

    if( temp -> data != PostOrder[idx++] )
    {
        cout<<"no"<<endl;
        exit(0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int N,i;
    cin>>N;

    int Position[N+1],PreOrder[N],PostOrder[N],InOrder[N];

    for( i=0; i<N ; i++ )
        cin>>PreOrder[i];

    for( i=0; i<N ; i++ )
        cin>>PostOrder[i];

    Position[0]=-1;
    for( i=0; i<N ; i++ )
    {
        cin>>InOrder[i];
        Position[InOrder[i]]=i+1;
    }

    MAKE_TREE( PreOrder, Position, N );

    CHECK( PostOrder, root );

    cout<<"yes"<<endl;

    return 0;
}
