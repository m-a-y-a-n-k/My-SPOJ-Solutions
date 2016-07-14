#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char ch)
{
    switch(ch)
    {
        case '^': return 3;

        case '*':
        case '/':
        case '%': return 2;

        case '+':
        case '-': return 1;

        case '$': return 0;
    }
    return -1;
}

int main()
{
    int T,i,x;
    string Infix;
    stack <char> S;
    cin>>T;
    while(T--)
    {
        i=0;
        cin>>Infix;
        Infix = "(" + Infix + ")$";
        while(1)
        {
            x = precedence(Infix[i]);
            if( x == 0 )
                break;
            if( x == -1 )
            {
                if( Infix[i] == ')' )
                {
                    while(S.top()!='(')
                    {
                        cout<<S.top();
                        S.pop();
                    }
                    S.pop();
                }
                else if( Infix[i] == '(' )
                {
                    S.push('(');
                }
                else
                {
                    cout<<Infix[i];
                }
            }
            else
            {
                while( x <= precedence(S.top()) )
                {
                    cout<<S.top();
                    S.pop();
                }
                S.push(Infix[i]);
            }
            i++;
        }
        while(!S.empty())
        {
            S.pop();
        }
        cout<<endl;
    }
    return 0;
}
