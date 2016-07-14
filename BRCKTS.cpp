#include <iostream>

using namespace std;

typedef struct SEGTREEnode
{
    int u,v;
    int L,R,E;
    SEGTREEnode *left,*right;
}Node;

int lL,eL,rL,rR,eR,lR;

char input[100000];

Node* build( Node *root, int a, int b )
{
    root = new Node;
    root -> u = a;
    root -> v = b;
    root -> left = root -> right = NULL;
    if( a == b )
    {
        if( input[a] == '(' )
        {
            root -> L = 1;
            root -> R = root -> E = 0;
        }
        else
        {
            root -> L = root -> E = 0;
            root -> R = 1;
        }
        return root;
    }
    root -> left = build( root -> left, a, (a+b)/2 );
    root -> right = build( root -> right, (1 + (a+b)/2 ), b );
    lL = root -> left -> L;
    eL = root -> left -> E;
    rL = root -> left -> R;
    lR = root -> right -> L;
    eR = root -> right -> E;
    rR = root -> right -> R;
    root -> E = eL + eR + min(lL,rR);
    root -> R = rL + rR - min(lL,rR);
    root -> L = lL + lR - min(lL,rR);
    //cout<<"IN RANGE: "<<a<<" to "<<b<<" left: "<<root->L<<" right: "<<root->R<<" pair: "<<root->E<<endl;
    return root;
}

void update( Node* root, int a )
{
    if( root -> u <= a && root -> v >= a )
    {
        if( root -> u == root -> v )
        {
            root -> L = 1 - root -> L;
            root -> R = 1 - root -> R;
            return ;
        }
        else
        {
            update( root -> left, a );
            update( root -> right, a );
        }
        //cout<<"UPDATED RANGE: "<<root->u+1<<" to "<<root->v<<endl;
        lL = root -> left -> L;
        eL = root -> left -> E;
        rL = root -> left -> R;
        lR = root -> right -> L;
        eR = root -> right -> E;
        rR = root -> right -> R;
        root -> E = eL + eR + min(lL,rR);
        root -> R = rL + rR - min(lL,rR);
        root -> L = lL + lR - min(lL,rR);
    }
}

int main()
{
    Node *Root;
    int M,x,n=0;
    while( cin>>M || n < 10 )
    {
        cout<<"Test "<<++n<<":"<<endl;
        cin>>input;
        Root = NULL;
        delete Root;
        Root = build( Root, 0 , M-1 );
        cin>>M;
        while(M--)
        {
            cin>>x;
            if( x == 0 )
            {
                if( Root -> L >0 || Root -> R > 0 )
                    cout<<"NO"<<endl;
                else
                    cout<<"YES"<<endl;
            }
            else
            {
                update(Root,x-1);
            }
        }
    }
    return 0;
}
