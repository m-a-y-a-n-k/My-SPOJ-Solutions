#include <cstdio>

int main()
{
    int n,m,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if( n <= m )
        {
            if( n%2 == 0 )
                printf("L");
            else
                printf("R");
        }
        else
        {
            if( m%2 == 1 )
                printf("D");
            else
                printf("U");
        }
        printf("\n");
    }
    return 0;
}
