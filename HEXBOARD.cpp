#include <iostream>

using namespace std;

int main()
{
    int n,i,j,s;
    while(cin>>n&&n>0)
    {
        for(i=1;i<=n;i++)
        {
            s=2*(n-i)+1;
            while(s--)
                cout<<" ";
            cout<<"_";
            s = i;
            while(--s)
                cout<<"/ \\_";
            cout<<endl;
        }
        for(i=1;i<=n;i++)
        {
            s = n;
            cout<<"/ \\";
            while(--s)
                cout<<"_/ \\";
            cout<<endl;
            cout<<"\\_/";
            s = n;
            while(--s)
                cout<<" \\_/";
            cout<<endl;
        }
        for(i=1;i<n;i++)
        {
            s = 2*i;
            while(--s)
                cout<<" ";
            s = n-i;
            while(s--)
                cout<<" \\_/";
            cout<<endl;
        }
        cout<<"***"<<endl;
    }
    return 0;
}
