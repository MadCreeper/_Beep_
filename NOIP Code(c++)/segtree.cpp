#include<bits/stdc++.h>
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define MAXN (int) 1e5+7
#define LL long long int
using namespace std;


struct segTree
{
    LL M,tag[MAXN*4],val[MAXN*4];

    void pushup(LL rt)
    {
        val[rt] = val[ls] + val[rs];
    }

    void pushdown(LL rt,LL len)
    {
        if(tag[rt]==0) return ;
        tag[ls] += tag[rt];
        tag[rs] += tag[rt];
        val[ls] += (len>>1) * tag[rt];
        val[rs] += (len>>1) * tag[rt];
        tag[rt] = 0;

        return ;
    }
    void build(LL n)
    {
      M=1;
       while(M<n)
            M<<=1; // 保证是满二叉树
       if(M>1) M--;
        memset(tag,0,sizeof(tag));
        for(int i=M+1;i<=M+n;i++) scanf("%d",&val[i]);
        for(int i=M+n+1;i<=(M<<1|1);i++) val[i]=0;
        for(int i=M;i>=1;i--) pushup(i);
    }
    void pt(int n)
    {
        for(int i=M+1;i<=M+n;i++) printf("%d ",val[i]);
        printf("\n");
    }
    void update(LL x,LL y,LL v,LL l,LL r,LL rt)
    {
        if(x<=l && y>=r)
        {
            tag[rt]+=v;
            val[rt]+=(r-l+1)*v;
            return ;
        }
        pushdown(rt,r-l+1);
        LL mid=(l+r)>>1;
        if(x<=mid) update(x,y,v,lson);
        if(y>mid) update(x,y,v,rson);
        pushup(rt);

    }

    LL query(LL x,LL y,LL l,LL r,LL rt)
    {
        if(x<=l && y>=r)
        {
            return val[rt];
        }
        pushdown(rt,r-l+1);
        LL mid=(l+r)>>1;
        LL ans=0;
        if(x<=mid) ans+=query(x,y,lson);
        if(y>mid)  ans+=query(x,y,rson);

        return ans;

    }

};


int main()
{
    int cas;
    cin>>cas;
    LL n;
    for(int i=1;i<=cas;i++)
    {
        printf("Case %d:\n",i);
        scanf("%lld",&n);
        segTree T;
        T.build(n);
        char op[100]; LL l,r;
        while(true)
        {
            scanf("%s",op);
            if(op[0]=='E') break;
            scanf("%lld%lld",&l,&r);
            if(op[0]=='Q') printf("%lld\n",T.query(l,r,1,n,1));
            if(op[0]=='A') T.update(l,l,r,1,n,1);
            if(op[0]=='S') T.update(l,l,-r,1,n,1);
            T.pt(n);
        }
    }
    return 0;
}
