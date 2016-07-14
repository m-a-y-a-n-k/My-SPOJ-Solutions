#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Node
{
    bool next[10];
    Node *links[10];
    bool complete;
};

int idx,len;
bool status;

bool add( string contact, Node **Root )
{
    Node *temp = *Root;
    idx = 0;
    len = contact.size();
    status = false;
    while( idx < len )
    {
        if( temp -> next[ contact[idx] - '0' ] == true )
        {
            temp = temp -> links[ contact[idx] - '0'];
            if( temp -> complete == true  )
            {
                if( idx == len - 1)
                    status = true;
                else
                    return false;
            }
        }
        else
        {
            temp -> next[contact[idx]-'0'] = true;
            temp -> links[contact[idx]-'0'] = (Node*)malloc(sizeof(Node));
            temp = temp -> links[contact[idx]-'0'];
            temp -> complete = false;
            for( int x = 0; x < 10; x++ )
            {
                temp -> next[x] = false;
                temp -> links[x] = NULL;
            }
            status = true;
        }
        if( temp -> complete == true && status == false )
        {
            return false;
        }
        if( ++idx == len )
                temp -> complete = true;
    }
    return status;
}

int main()
{
    int tests,n;
    string contact;
   // cout << "Test Cases ?" <<endl;
    cin >> tests;
    bool prefix;
    while(tests--)
    {
        Node *root = (Node*)malloc(sizeof(Node));
        root -> complete = false;
        for( idx = 0; idx < 10; idx++ )
        {
            root -> next[idx] = false;
            root -> links[idx] = NULL;
        }
        //cout << "Number of phones?" << endl;
        cin >> n;
        prefix = false;
        while(n--)
        {
            cin >> contact;
            if( add(contact,&root) == false )
            {
                prefix = true;
                break;
            }
        }
        if( prefix == true )
        {
            cout << "NO" <<endl;
            while(n--)
            {
                cin >> contact;
            }
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
