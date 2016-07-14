#include <stdio.h>

int main()
{
    int a,b,ans[100001],T,i,n,q,test=1;
    scanf("%d",&T);
    ans[1]=1;
    while(T--)
    {
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if(i>=2)
            {
                if(b!=a)
                    ans[i]=ans[i-1]+1;
                else
                    ans[i]=ans[i-1];
            }
            b=a;
        }
        printf("Case %d:\n",test++);
        while(q--)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",ans[b]-ans[a]+1);
        }
    }
    return 0;
}
