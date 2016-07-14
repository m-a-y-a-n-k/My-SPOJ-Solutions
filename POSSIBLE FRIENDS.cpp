#include <iostream>
#include <string>

using namespace std;

string matrix[51],line;
int fof[51];

int main()
{
    int t,T,i,l,j,k,m,w;
    cin>>T;
    for( t = 0; t < T; t++ )
    {
        cin>>line;
        l = line.size();
        matrix[0] = line;
        for(i=0;i<l;i++)
        {
            fof[i]=0;
            if(i>0)
            {
                cin>>matrix[i];
            }
        }
        for(i=0;i<l;i++)
        {
            for(j=i+1;j<l;j++)
            {
                if(matrix[i][j]=='N')               // j is not a friend of i
                {
                    for(k=0;k<l;k++)
                    {
                        if(matrix[j][k]=='Y'&&matrix[i][k]=='Y')             // k is a common friend of j and i
                        {
                            fof[j]++;
                            fof[i]++;
                            break;
                        }
                    }
                }
            }
        }
        m = 0;
        w = 0;
        for( i=0; i<l; i++ )
            if( fof[i] > m )
            {
                m = fof[i];
                w = i;
            }
        cout<<w<<" "<<m<<endl;
    }
    return 0;
}
