#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long num,ds=0,t,n;
    cin>>t;
    for(n=0;n<t;n++)
    {
        priority_queue <int> HMAX;
        priority_queue <int> HMIN;
        while(HMAX.size()==0)
        {
            cin>>num;
            if( num == -1 )
            {
                break;
            }
            if(num==0)
                break;
            HMAX.push(num);
            cin>>num;
            if(num == -1)
            {
                cout<<HMAX.top()<<endl;
                HMAX.pop();
            }
            else
            {
                HMIN.push(-num);
            }
        }
        if(num==0)
        {
            cout<<endl;
            continue;
        }
        while(cin>>num)
        {
            if( num == -1 )
            {
                if( HMAX.size() != 0 )
                {
                    cout<<HMAX.top()<<endl;
                    HMAX.pop();
                    if(ds == 0)
                    {
                        HMAX.push(-HMIN.top());
                        HMIN.pop();
                        ds = 1;
                    }
                    else
                        ds=0;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if( num == 0 )
                    break;
                if(ds==0)
                {
                    ds=1;
                    HMAX.push(num);
                }
                else
                {
                    ds=0;
                    HMIN.push(-num);
                }
                while(HMAX.top()>(-HMIN.top()))
                {
                    HMIN.push(-HMAX.top());
                    HMAX.push(-HMIN.top());
                    HMIN.pop();
                    HMAX.pop();
                }
            }
        }
        if(num==0)
            cout<<endl;
    }
    return 0;
}
