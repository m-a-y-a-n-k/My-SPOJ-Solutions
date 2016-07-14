#include <bits/stdc++.h>

using namespace std;

char g[52][52];

bool vis[52][52];

long long height[52][52],ans;

long long solve(int i,int j)
{
    if(g[i][j]=='x'||vis[i][j]==true)
    {
        return height[i][j];
    }

    vis[i][j]=true;

    if(g[i+1][j+1]-g[i][j]==1)
        height[i][j]=max(height[i][j],solve(i+1,j+1)+1);
    if(g[i-1][j-1]-g[i][j]==1)
        height[i][j]=max(height[i][j],solve(i-1,j-1)+1);
    if(g[i-1][j+1]-g[i][j]==1)
        height[i][j]=max(height[i][j],solve(i-1,j+1)+1);
    if(g[i+1][j-1]-g[i][j]==1)
        height[i][j]=max(height[i][j],solve(i+1,j-1)+1);
    if(g[i+1][j]-g[i][j]==1)
        height[i][j]=max(height[i][j],solve(i+1,j)+1);
    if(g[i-1][j]-g[i][j]==1)
        height[i][j]=max(height[i][j],solve(i-1,j)+1);
    if(g[i][j+1]-g[i][j]==1)
        height[i][j]=max(height[i][j],solve(i,j+1)+1);
    if(g[i][j-1]-g[i][j]==1)
        height[i][j]=max(height[i][j],solve(i,j-1)+1);

    return height[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    int H,W,i,j;
    int c=1;
    while(1)
    {
        ans=0;

        cin>>H>>W;
        for(i=0;i<=H+1;i++)
            for(j=0;j<=W+1;j++)
            {
                height[i][j]=0;
                g[i][j]='x';
                vis[i][j]=false;
            }
        if(H==0&&W==0)
            break;
        for(i=0;i<=H+1;i++)
        {
            for(j=0;j<=W+1;j++)
            {
                if(i==0||j==0)
                {
                    g[i][j]='x';
                }
                else if(i==H+1||j==W+1)
                {
                    g[i][j]='x';
                }
                else
                    cin>>g[i][j];
            }
        }
        for(i=1;i<=H;i++)
        {
            for(j=1;j<=W;j++)
            {
                if(g[i][j]=='A')
                {
                    ans=max(ans,solve(i,j)+1);
                }
            }
        }
        cout<<"Case "<<c++<<": "<<ans<<endl;
    }
    return 0;
}
