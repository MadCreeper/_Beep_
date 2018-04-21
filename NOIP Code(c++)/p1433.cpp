#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
    double x,y;
}g[100];
double ans=99999999;
bool vis[20];
double len(int a,int b)
{
    double x1=g[a].x,y1=g[a].y,x2=g[b].x,y2=g[b].y;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(int p,double step,int depth)
{
    //cout<<p<<endl;
    vis[p]=true;
    if(depth==n && step<ans)
    {
        ans=step;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i,step+len(p,i),depth+1);
            vis[i]=false;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>g[i].x>>g[i].y;
    g[0].x=0.0,g[0].y=0.0;
    dfs(0,0.0,0);
    cout.setf(ios::fixed);
    cout<<setprecision(2)<<ans<<endl;
}
