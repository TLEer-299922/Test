#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int x0,y0;
char maps[10][10];
int vis[10][10];
int dir[8][2]={{-2,1},{-2,-1},{-1,2},{-1,-2},{2,1},{2,-1},{1,2},{1,-2}};
int cnt;
void dfs(int x,int y,int step)
{
    if(step==n*m)
    {
        cnt++;
        return;
    }
    for(int i=0;i<8;i++)
    {
        int nx=x+dir[i][0];
        int ny=y+dir[i][1];
        if(nx>=0&&ny>=0&&nx<n&&ny<m&&vis[nx][ny]==0)
        {
            vis[nx][ny]=1;
            dfs(nx,ny,step+1);
            vis[nx][ny]=0;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cnt=0;
        memset(vis,0,sizeof(vis));
        cin>>n>>m;
        cin>>x0>>y0;
        vis[x0][y0]=1;
        dfs(x0,y0,1);
        cout<<cnt<<endl;
    }
  return 0;
}