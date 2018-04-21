#include<bits/stdc++.h>
using namespace std;
struct node
{
    int l,r;
}a[100000+10];
int n,m;
void addleft(int f,int t) //put f to the left of t
{
    int tmp=a[t].l;
    a[a[t].l].r=f;
    a[t].l=f;
    a[f].r=t;
    a[f].l=tmp;
}
void addright(int f,int t)
{
    int tmp=a[t].r;
    a[a[t].r].l=f;
    a[t].r=f;
    a[f].l=t;
    a[f].r=tmp;
}
void _erase(int t)
{
    a[a[t].l].r=a[t].r;
    a[a[t].r].l=a[t].l;
    a[t].l=0;
    a[t].r=100005;
}
int main()
{
    cin>>n;
    a[1]=(node){0,100005};
    int x,p;
    for(int i=2;i<=n;i++)
    {
        scanf("%d%d",&x,&p);
        if(p==0) addleft(i,x);
        if(p==1) addright(i,x);
    }
    cin>>m;
    while(m--)
    {
        scanf("%d",&x);
        if((a[x].l==0 && a[x].r==100005) || x>n) continue;
        else _erase(x);
    }

    int pos=0;
    while(a[pos].r!=100005) {
            cout<<a[pos].r<<" ";
            pos=a[pos].r;
    }

}
