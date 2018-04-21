#include<bits/stdc++.h>
using namespace std;
int n,m;
int g[110][110];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int v[110][110]={0};
int maxstep=0;
struct node
{
    int x,y,h;
}ss[110*100];
bool cmp(node a, node b)
{
    return a.h>b.h;
}
void dfs(int x,int y,int step)
{
    if(step>maxstep) maxstep=step;
    if(step>v[x][y]) v[x][y]=step;
    if(step<v[x][y]) return ;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=1 && nx<=n && ny>=1 && ny<=m && g[nx][ny]<g[x][y])
        {
            dfs(nx,ny,step+1);
        }
    }
}
int main()
{
    cin>>n>>m;
    int pos=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&g[i][j]);
            ss[pos++]=(node){i,j,g[i][j]};
        }
        sort(ss,ss+n*m,cmp);
     for(int i=1;i<=n*m;i++)
        {

           if(!v[ss[i].x][ss[i].y]) dfs(ss[i].x,ss[i].y,1);
        }
        cout<<maxstep+1<<endl;
}
