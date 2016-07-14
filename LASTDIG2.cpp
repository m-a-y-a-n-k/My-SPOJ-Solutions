#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T,d[10][5]={{0,0,0,0,0},{0,1,1,1,1},{0,2,4,8,6},{0,3,9,7,1},{0,4,6,4,6},{0,5,5,5,5},{0,6,6,6,6},{0,7,9,3,1},{0,8,4,2,6},{0,9,1,9,1}};
    string base;
    long long expo;
    cin>>T;
    while(T--)
    {
        cin>>base;
        cin>>expo;
        if(expo==0)
        {
            cout<<1<<endl;
            continue;
        }
        expo = expo % 4;
        if(expo==0)
            expo=4;
        cout<<d[base[base.size()-1]-48][expo]<<endl;
    }
    return 0;
}
