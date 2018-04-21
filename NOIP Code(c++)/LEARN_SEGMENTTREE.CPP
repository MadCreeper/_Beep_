#include<bits/stdc++.h>
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define mid ((l+r)>>1)
#define LL long long
using namespace std;

const int maxn=400000;
LL n,m;
LL A[maxn];
LL xds[4*maxn];
LL tag[4*maxn];
inline void pushup(LL rt)
{
    xds[rt]=xds[ls]+xds[rs];
}
void pushdown(LL rt,LL l,LL r)
{
    if(tag[rt]!=0)
    {
        xds[ls]+=(mid-l+1)*tag[rt];
        xds[rs]+=(r-(mid+1)+1)*tag[rt];
        tag[ls]+=tag[rt];
        tag[rs]+=tag[rt];
        tag[rt]=0;
    }

}
void build(LL rt,LL l,LL r)
{
    if(l==r)
        {
            xds[rt]=A[l];
                return ;
        }

        build(lson);
        build(rson);
        pushup(rt);

}
LL query(LL rt,LL l,LL r,LL a,LL b) // l,r 当前左右 a,b 要查询的左，右
{
    pushdown(rt,l,r);
    if(a<=l && r<=b)
    {
        return xds[rt];
    }

    LL ans=0;
    if(a<=mid) ans+=query(lson,a,b);
    if(b>mid) ans+=query(rson,a,b);
        return ans;
}
void seg_update(LL rt,LL l,LL r,LL a,LL b,LL c) // 将 a-b的值 +c
{
    pushdown(rt,l,r);
    if(a<=l && r<=b)
    {
        xds[rt]+=(r-l+1)*c;
        tag[rt]+=c;
            return ;
    }
    if(a<=mid) seg_update(lson,a,b,c);
    if(b>mid)  seg_update(rson,a,b,c);
    pushup(rt);

}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&A[i]);

    }
    build(1,1,n);

    for(LL i=1,a,b,c,d;i<=m;i++)
    {
        scanf("%lld",&a);
        if(a==1)
        {
            scanf("%lld%lld%lld",&b,&c,&d);
            seg_update(1,1,n,b,c,d);
        }
        if(a==2)
        {
            scanf("%lld%lld",&b,&c);
            printf("%lld\n",query(1,1,n,b,c));
        }
    }
}
