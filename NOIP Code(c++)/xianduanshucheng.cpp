#include<bits/stdc++.h>
#include<iostream>
#define LL long long
#define lson (p<<1),l,mid
#define rson (p<<1|1),mid+1,r
#define ls (p<<1)
#define rs (p<<1|1)
LL mo,n,m;
using namespace std;
const int maxn=1000100;
LL N[maxn];
struct p
{
 LL v,add,mul;
}t[maxn<<2];
void pushup(LL p)
{
    t[p].v=t[ls].v+t[rs].v;
    t[p].v%=mo;
}
void pushdown(LL p,LL l,LL r)
{
    LL mid=(l+r)>>1;
    if(t[p].mul!=1)
    {
        LL tmp=t[p].mul;
        t[p].mul=1;
        t[ls].v*=tmp;
        t[ls].v%=mo;
        t[ls].mul*=tmp;
        t[ls].mul%=mo;
        t[ls].add*=tmp;
        t[ls].add%=mo;

        t[rs].v*=tmp;
        t[rs].v%=mo;
        t[rs].mul*=tmp;
        t[rs].mul%=mo;
        t[rs].add*=tmp;
        t[rs].add%=mo;
    }
       if(t[p].add!=0)
       {
        LL tmp=t[p].add;
        t[p].add=0;
        t[ls].v+=(mid-l+1)*tmp;
        t[ls].v%=mo;
        t[ls].add+=tmp;
        t[ls].add%=mo;

        t[rs].v+=(r-mid)*tmp;
        t[rs].v%=mo;
        t[rs].add+=tmp;
        t[rs].add%=mo;
       }
}

void build(LL p,LL l,LL r)
{
    t[p].add=0;
    t[p].mul=1;
    LL ct;
    if(l>r) return ;
    if(l==r)
    {

        t[p].v=N[l]%mo;
        return ;
    }
    LL mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(p);
}
void update(LL p,LL l,LL r,LL x,LL y,LL num,LL type)
{
    pushdown(p,l,r);
    if(x<=l && r<=y)
    {
        if(type==1)
        {
            t[p].v*=num;
            t[p].v%=mo;
            t[p].mul*=num;
            t[p].mul%=mo;
        }
        else if(type==2)
        {
            t[p].v+=(r-l+1)*num;
            t[p].v%=mo;
            t[p].add    +=num;
            t[p].add%=mo;
        }
        return ;
    }

    LL mid=(l+r)>>1;
    if(x<=mid) update(lson,x,y,num,type);
    if(mid<y) update(rson,x,y,num,type);
    pushup(p);
}
LL query(LL p,LL l,LL r,LL x,LL y)
{
    pushdown(p,l,r);
    if(x<=l && r<=y)
    {
        return t[p].v;
    }
        LL ans=0;

        LL mid=(l+r)>>1;
        if(x<=mid) { ans+=query(lson,x,y);ans%=mo;}
        if(mid<y) { ans+=query(rson,x,y);ans%=mo;}
        return ans;


}
int main()
{
    cin>>n>>m>>mo;
    for(int i=1;i<=n;i++)
        scanf("%lld",&N[i]);
    build(1,1,n);
    LL op,x,y,k;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&op);
       // cout<<op<<endl;
        if(op==3)
        {
           scanf("%d%d",&x,&y);

            printf("%lld\n",query(1,1,n,x,y)%mo);
        }
        else
        {
            scanf("%lld%lld%lld\n",&x,&y,&k);
            update(1,1,n,x,y,k,op);
        }

    }
    return 0;
}
