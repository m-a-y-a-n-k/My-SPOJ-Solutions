#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string num;
    int i,y,x,t=1024;
    while(t--)
    {
        cin>>num;
        y=0;
        x = num.length();
        reverse(num.begin(),num.end());
        if(num=="0")
        {
            cout<<-2<<endl;
            continue;
        }
        if(num=="1")
        {
            cout<<1<<endl;
            continue;
        }
        num = num + "0";
        for( i=0; i<x && num[i]=='0'; i++ )
        {
                num[i]='9';
        }
        num[i] = num[i] - 1;
        for( i=0; i<=x; i++ )
        {
            y = y + num[i]-'0' + num[i] - '0' ;
            num[i] = y%10 + '0';
            y = y/10;
        }
        reverse(num.begin(),num.end());
        for(i=0;i<=x;i++)
        {
            if(i==0&&num[i]=='0')
                continue;
            else
                cout<<num[i];
        }
        cout<<endl;
    }
    return 0;
}
