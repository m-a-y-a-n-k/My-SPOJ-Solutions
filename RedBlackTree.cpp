#include <bits/stdc++.h>

using namespace std;

#define RED 0
#define BLACK 1

struct RBT{
    int key,color;
    RBT *parent,*left,*right;
 };
RBT *root,*leaf = NULL;

void LeftRotate( RBT* root, RBT* x) {
    RBT *y;
    y = x -> right;
    x -> right = y -> left;
    if( y -> left != leaf ) {
        y -> left -> parent = x;
    }
    y -> parent = x -> parent;

    if( x -> parent == leaf ){
        root = y;
    }
    else if( x == x -> parent -> left ){
        x -> parent -> left = y;
    }
    else {
        x -> parent -> right = y;
    }
    y -> left = x;
    x -> parent = y;
}

void RightRotate( RBT* root, RBT* y) {
    RBT *x;
    x = y -> left;
    y -> left = x -> right;
    if( x -> right != leaf ) {
        x -> right -> parent = y;
    }
    x -> parent = y -> parent;

    if( y -> parent == leaf ){
        root = x;
    }
    else if( y == y -> parent -> left ){
        y -> parent -> right = x;
    }
    else {
        y -> parent -> left = x;
    }
    x -> right = y;
    y -> parent = x;
}

void RBInsertFixUp( RBT* root, RBT* z) {

    RBT *y;
    while( z -> parent -> color == RED ) {
        if( z -> parent == z -> parent -> parent -> left ) {
            y = z -> parent -> parent -> right;
            if( y -> color == RED ) {
                z -> parent -> color = BLACK;
                y -> color = BLACK;
                z -> parent -> parent -> color = RED;
                z = z -> parent -> parent;
            }
            else if( z -> parent -> right == z ) {
                z = z -> parent;
                LeftRotate( root, z);
                z -> parent -> color = BLACK;
                z -> parent -> parent -> color = RED;
                RightRotate( root, z -> parent -> parent);
            }
        }
        else{
            y = z -> parent -> parent -> left;
            if( y -> color == RED ) {
                z -> parent -> color = BLACK;
                y -> color = BLACK;
                z -> parent -> parent -> color = RED;
                z = z -> parent -> parent;
            }
            else if( z -> parent -> left == z ) {
                z = z -> parent;
                RightRotate( root, z);
                z -> parent -> color = BLACK;
                z -> parent -> parent -> color = RED;
                LeftRotate( root, z -> parent -> parent);
            }
        }
    }
}

void RBInsert( RBT* root, RBT* z) {

    RBT *y,*x;
    y = leaf;
    x = root;
    while( x != leaf ) {

        y = x;
        if( z -> key < x -> key ) {
            x = x -> left;
        }
        else {
            x = x -> right;
        }
    }

    z -> parent = y;
    if( y == leaf ) {
        root = z;
    }
    else if( z -> key < y -> key ) {
        y -> left = z;
    }
    else {
        y -> right = z;
    }

    z -> left = leaf;
    z -> right = leaf;
    z -> color = RED;
    RBInsertFixUp(root,z);
}

void printTree( RBT *root) {

    if( root == leaf )
        return;
    printTree( root -> left);
    printTree( root -> right);
    cout << "--------------------------" << endl;
    cout << root -> key << "has :" << endl;
    cout << "1.Color - " << endl;
    if( root -> color )
        cout << "RED" << endl;
    else
        cout << "BLACK" << endl;
    cout << "2.Left Child - " << root -> left -> key << endl;
    cout << "3.Right Child - " << root -> right -> key << endl;
}

int main() {

    RBT *newNode;
    int n;
    cout << "Enter number of nodes in Red Black Tree" << endl;
    cin >> n;
    root = (RBT *)malloc(sizeof(RBT)*n);
    cout << "Insert node into Red Black Tree one by one" << endl;
    for( int i = 0; i < n; i++ ) {
        cout << "Enter key value of node " << i + 1 << endl;
        newNode = (RBT*) malloc(sizeof(RBT));
        newNode -> parent = leaf;
        newNode -> left = newNode -> right = NULL;
        cin >> newNode -> key;
        RBInsert(root,newNode);
    }
    printTree(root);
    return 0;
}
