#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int result[2001][2001];

int main()
{
    string one,two;
    int T,i,j,s1=0,s2=0;

    cin>>T;

    while(T--)
    {
        cin>>one>>two;

        one = "$" + one;
        two = "$" + two;

        s1 = one.size();
        s2 = two.size();

        for(i=0;i<s2;i++)
        {
            result[0][i] = i;
        }

        for(i=1;i<s1;i++)
        {
            result[i][0] = i;
        }

        for(i=1;i<s1;i++)
        {
            for(j=1;j<s2;j++)
            {
                if(one[i]==two[j])
                {
                    result[i][j]=result[i-1][j-1];
                }
                else
                {
                    result[i][j]=min(result[i-1][j-1],min(result[i-1][j],result[i][j-1]));
                    result[i][j]++;
                }
            }
        }

        cout<<result[s1-1][s2-1]<<endl;
    }
    return 0;
}
