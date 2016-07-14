#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    bool visit[N],mark=false;
    int i,data[N],j,next=1,interval,Count=0;
    for(i=0;i<N;i++)
    {
        cin>>data[i];
        visit[i]=false;
    }
    visit[0]=true;
    for( i=1; i<N;  )
    {
        if( visit[i] == false )
        {
            interval = data[i] - data[0];
            visit[i] = true;
            j = data[i];
            while( j <= data[N-1] )
            {
                if( N == ++i )
                    break;

                if( data[i] == j + interval )
                {
                    j = j + interval;
                    visit[i]=true;
                }
                else if( data[i] < j + interval )
                {
                    if( mark == false )
                    {
                        if(visit[i]==false)
                        {
                            next = i;
                            mark = true;
                        }
                        else
                        { next = i+1;}
                    }
                }
            }
            i = next;
            mark = false;
            Count++;
        }
        else
        {
            i++;
        }
    }
    cout<<Count<<endl;
    return 0;
}
