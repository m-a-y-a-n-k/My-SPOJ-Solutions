#include <bits/stdc++.h>

using namespace std;

bool grid[15][15];
    // grid of 10 x 10 with base at (2,2)....and end at (11,11)...
int ans;

bool stop(int r,int c)
{
    if(r>=1&&c>=2&&grid[r-1][c-2]==true)
        return false;
    if(r>=1&&c<=11&&grid[r-1][c+2]==true)
        return false;
    if(r>=2&&c>=1&&grid[r-2][c-1]==true)
        return false;
    if(r>=2&&c<=11&&grid[r-2][c+1]==true)
        return false;
    if(r<=11&&c<=11&&grid[r+1][c+2]==true)
        return false;
    if(r<=11&&c>=2&&grid[r+1][c-2]==true)
        return false;
    if(r<=11&&c>=1&&grid[r+2][c-1]==true)
        return false;
    if(r<=11&&c<=11&&grid[r+2][c+1]==true)
        return false;
    return true;                                // returns true if all 8 positions are blocked ..
}

void solve(int start,int r,int cnt)                  //start represents col in current row r
{
    bool flag=false;

    if(grid[r][start]==false)
        return ;
    else
        flag=true;

    grid[r][start]=false;                   // The cell is now blocked..

    if(stop(r,start)==true)                 //If no further move is possible
    {
        if(flag)
           grid[r][start]=true;
        if(ans<cnt)
            ans=cnt;
        return ;
    }

    solve(start-1,r-2,cnt+1);
    solve(start+1,r-2,cnt+1);
    solve(start-2,r-1,cnt+1);
    solve(start+2,r-1,cnt+1);
    solve(start-2,r+1,cnt+1);
    solve(start+2,r+1,cnt+1);
    solve(start-1,r+2,cnt+1);
    solve(start+1,r+2,cnt+1);

    if(flag)
        grid[r][start]=true;                      // The cell is now allowed if it was allowed before..
    if(ans<cnt)
        ans=cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int i,N,s,l,j,C=0,start,total;
    while(1)
    {
        for(i=0;i<14;i++)
          for(j=0;j<14;j++)
            {
                grid[i][j]=false;            // false denotes blocked cell
            }
        cin>>N;
        if(N==0)
            break;
        j=1;
        start=2,total=ans=0;
        while(++j<=N+1)
        {
            cin>>s>>l;
            if(j==2)
                start=s+2;
            for(i=s+2;i<=s+l+1;i++)
            {
                grid[j][i]=true;                // true denotes allowed cell
            }
            total+=l;
        }
        solve(start,2,1);
        if(total-ans==1)
            cout<<"Case "<<++C<<", "<<"1 square can not be reached."<<endl;
        else
            cout<<"Case "<<++C<<", "<<total-ans<<" squares can not be reached."<<endl;
    }
    return 0;
}
