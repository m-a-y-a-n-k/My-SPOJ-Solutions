#include<stdio.h>
int main()
{
    float arr[275];
    int i;
    for(i=0;i<275;i++)    
    {
        arr[i]=1.0/(2.0+i);
    }
    float t;
    scanf("%f",&t);
    while(t)
    {
        float sum=0;
        for(i=0;i<275;i++)
         {
             sum+=arr[i];
             if(sum>=t)
                break;
        }
        printf("%d card(s)\n",i+1);
        scanf("%f",&t);
    }
    return 0;
}