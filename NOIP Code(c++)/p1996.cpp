#include<bits/stdc++.h>
using namespace std;
struct node
{
    int l,r;
}a[1000+10];
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
    a[t].r=1005;
}
int main()
{
    cin>>n>>m;
    for(int i=2;i<=n;i++)
    {
        a[i].r=i+1;
        a[i].l=i-1;
    }
    a[1].l=n;
    a[1].r=2;
    a[n].l=n-1;
    a[n].r=1;
    int pos=1;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<m;i++)
        {
            pos=a[pos].r;
        }
        int temp=a[pos].r;
        cout<<pos<<" ";
        _erase(pos);
        pos=temp;
    }
}

