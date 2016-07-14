#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    unsigned int height;
    char data;
    Node *left,*right;
};

Node* Insert( Node* Root, char& ch )
{
    Node *root = ( Node* )malloc( sizeof(Node) );
    root -> left = root -> right = NULL;
    if( ch == '\r' )
    {
        return NULL;
    }
    if( ch == 'l' )
    {
        root -> data = ch;
        root -> height = 0;
        return root;
    }
    if( ch == 'n' )
    {
        root -> data = ch;
        cin>>ch;
        root -> left = Insert( root -> left, ch );
        cin>>ch;
        if(ch=='\r')
        {
            root -> right = NULL;
        }
        else
        {
            root -> right = Insert( root -> right, ch );
        }
        root -> height = max( root -> left -> height, root -> right -> height ) + 1;
        return root;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    Node *root = NULL;
    char ch;
    cin>>T;
    while(T--)
    {
        cin>>ch;
        root = Insert( root, ch );
        cout<<root -> height<<endl;
    }
    return 0;
}
