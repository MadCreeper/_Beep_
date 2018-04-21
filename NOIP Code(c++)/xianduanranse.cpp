#include<bits/stdc++.h>
#define ls (p<<1)
#define rs (p<<1|1)
#define maxn 2000100
using namespace std;
struct node
{
    int l,r,color;
}t[maxn*4];
int	n,T;
int cutted,rest;
void pushdown(int p)
{
    if(t[p].color!=1 && t[p].color!=-1)
    {
    t[ls].color=t[p].color;
    t[rs].color=t[p].color;

    }
}
void build(int p,int l,int r)
{

    t[p].l=l;
    t[p].r=r;
    t[p].color=1;

    if(l==r)
        return ;

    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void pushup(int p)
{
    if(t[ls].color==t[rs].color)
     t[p].color=t[ls].color;
    else
        t[p].color = -1;

}
void cut(int p,int l,int r)
{
//	printf("P:%d	l:%d	r:%d\n",p,l,r);
    int mid=(t[p].l+t[p].r)>>1;
    pushdown(p);
    if(t[p].l==l && t[p].r==r)
    {
        if(t[p].color==0) return ;
        //if(t[p].color==1)	t[p].color=0;
        if(t[p].color==1)
        {
            t[p].color=0;
            cutted+=(t[p].r-t[p].l+1);
            rest-=(t[p].r-t[p].l+1);
        }
        if(t[p].color==-1)
        {
            t[p].color=0;
            cut(ls,l,mid);
            cut(rs,mid+1,r);

        }
    }
    else
    {
        if(r<=mid) cut(ls,l,r);
        else if(l>mid) cut(rs,l,r);
        else
        {
            cut(ls,l,mid);
            cut(rs,mid+1,r);
        }
        pushup(p);
    }
}

void plant(int p,int l,int r)
{
    int mid=(t[p].l+t[p].r)>>1;
    pushdown(p);
    if(t[p].l==l && t[p].r==r)
    {
        if(t[p].color==0)
        {
            t[p].color=1;
            rest+=(t[p].r-t[p].l)+1;
        }
        if(t[p].color==1 )	return ;


        if(t[p].color==-1)
        {
            plant(ls,l,mid);
            plant(rs,mid+1,r);
        }
    }
    else
    {

        if(r<=mid) plant(ls,l,r);
        else if(l>mid) plant(rs,l,r);
        else
        {
            plant(ls,l,mid);
            plant(rs,mid+1,r);
        }
        pushup(p);
    }
}
int main(){
    cin>>n>>T;

    int op,x,y;
    build(1,0,n);
    plant(1,0,n);
    while(T--)
    {
        cin>>x>>y;


            cut(1,x,y);
        cout<<n-cutted<<endl;
    }

}
