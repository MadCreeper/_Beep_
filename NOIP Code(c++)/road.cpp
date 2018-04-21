#include<bits/stdc++.h>
#define maxn 10010
using namespace std;
int n,m;
int bg,ed;
vector<int> g[2][maxn];
bool vis[maxn]={0};
int tag[maxn]={0};
int dfs(int s,int e)
{
    vis[s]=1;
    for(int i=0;i<g[1][s].size();i++)
    {
        if(vis[g[1][i]]) continue;
         dfs(i,e);
    }
}
struct node
{
    int v,step;
};
void bfs(int s,int e)
{
    queue<node> Q;
    Q.push((node){s,0});
    while(!Q.empty())
    {
        int step=Q.front().step , cur=Q.front().v;
        tag[cur]=1;
        for(int i=0;i<g[0][cur].size();i++)
        {
            if(!vis[g[0][i]])
            {
             Q.push((node){g[0][i],step+1});
            }
        }
    }

}
int main()
{
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[0][a].push_back(b);
        g[1][b].push_back(a);
    }

    cin>>bg>>ed;
    dfs(ed,bg);

    for(int i=1;i<=n;i++)
        cout<<vis[i]<<" ";


}
