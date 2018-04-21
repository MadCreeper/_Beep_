#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <set>
using namespace std;
#define ll long long
#define ld long double
#define tt ll//线段树数据格式
#define ts 100000//线段树大小
int p, n, m;
struct stree //节点数据结构
{
    tt v;//节点值
    tt a;//节点加法标记
    tt cs;//节点子节点个数
    tt m;//节点乘法标记
}t[ts * 4 + 1];
//建树
void cstree(tt rt, tt a[], tt st, tt ed)//根节点rt;输入数组a[];当前区间st,ed
{
    t[rt].a = 0;
    t[rt].m = 1;
    if (st == ed)//无子节点
    {
        t[rt].v = a[st];
        t[rt].cs = 1;
        return;
    }
    tt md = (st + ed) >> 1;//中点
                           //递归建树
    cstree(rt * 2, a, st, md);
    cstree(rt * 2 + 1, a, md + 1, ed);
    //根据子节点产生父节点
    t[rt].v = (t[rt * 2].v % p) + (t[rt * 2 + 1].v % p) % p;//子节点值和
    t[rt].cs = t[rt * 2].cs + t[rt * 2 + 1].cs;//子节点个数
}
//处理标记
inline void pushdown(tt rt)//根节点rt
{
    if (t[rt].m!=1)//存在乘法标记
    {
        //左子节点修改
        //处理值
        t[rt * 2].v *= t[rt].m;
        t[rt * 2].v %= p;
        //处理加法标记
        t[rt * 2].a *= t[rt].m;
        t[rt * 2].a %= p;
        //标记下放
        t[rt * 2].m *= t[rt].m;
        t[rt * 2].m %= p;
        //右子节点修改
        //处理值
        t[rt * 2 + 1].v *= t[rt].m;
        t[rt * 2 + 1].v %= p;
        //处理加法标记
        t[rt * 2 + 1].a *= t[rt].m;
        t[rt * 2 + 1].a %= p;
        //标记下放
        t[rt * 2 + 1].m *= t[rt].m;
        t[rt * 2 + 1].m %= p;
        //清空标记
        t[rt].m = 1;
    }
    if (t[rt].a)//存在加法标记
    {
        //子节点修改
        //左
        t[rt * 2].v += (t[rt].a%p)*t[rt * 2].cs;
        t[rt * 2].v %= p;
        //右
        t[rt * 2 + 1].v += (t[rt].a%p)*t[rt * 2 + 1].cs;
        t[rt * 2 + 1].v %= p;
        //下放标记
        //左
        t[rt * 2].a += t[rt].a;
        t[rt * 2].a %= p;
        //右
        t[rt * 2 + 1].a += t[rt].a;
        t[rt * 2 + 1].a %= p;
        //清空标记
        t[rt].a = 0;
    }
}
//搜索
tt sstree(tt rt, tt nst, tt ned, tt sst, tt sed)//根节点rt;现在区间nst,ned;搜索区间sst,sed
{
    if (sst>ned || sed<nst)//搜索区间和现在区间无交集
        return 0;
    if (sst <= nst && sed >= ned)//搜索区间包含现在区间
        return t[rt].v % p;
    //搜索区间和现在区间有交集
    pushdown(rt);//处理标记
    tt md = (nst + ned) >> 1;//中点
    return (sstree(rt * 2, nst, md, sst, sed) % p + sstree(rt * 2 + 1, md + 1, ned, sst, sed) % p) % p;//递归搜索子节点
}
//乘法更新
void updatemul(tt rt, tt nst, tt ned, tt ust, tt ued, tt mul)//根节点rt;现在区间nst,ned;更改区间ust,ued;增加量mul
{
    if (ust>ned || ued<nst)//更改区间和现在区间无交集
        return;
    if (ust <= nst && ued >= ned)//更改区间包含现在区间
    {
        //加法标记
        t[rt].a *= mul;
        t[rt].a %= p;
        //值
        t[rt].v *= mul;
        t[rt].v %= p;
        //乘法标记
        t[rt].m *= mul;
        t[rt].m %= p;
        return;
    }
    //更改区间和现在区间有交集
    pushdown(rt);//处理标记
    tt md = (nst + ned) >> 1;//中点
                             //递归更新
    updatemul(rt * 2, nst, md, ust, ued, mul);
    updatemul(rt * 2 + 1, md + 1, ned, ust, ued, mul);

    //更改当前值
    t[rt].v = (t[rt * 2].v % p + t[rt * 2 + 1].v % p) % p;
}
// 加法更新
void updateadd(tt rt, tt nst, tt ned, tt ust, tt ued, tt add)//根节点rt;现在区间nst,ned;更改区间ust,ued;增加量add
{
    if (ust>ned || ued<nst)//更改区间和现在区间无交集
        return;
    if (ust <= nst && ued >= ned)//更改区间包含现在区间
    {
        t[rt].a += (add % p );
        t[rt].a %= p;
        t[rt].v += (add % p) * t[rt].cs;
        t[rt].v %= p;
        return;
    }
    //更改区间和现在区间有交集
    pushdown(rt);//处理标记
    tt md = (nst + ned) >> 1;//中点
    //递归更新
    updateadd(rt * 2, nst, md, ust, ued, add);
    updateadd(rt * 2 + 1, md + 1, ned, ust, ued, add);
    //更改当前值
    t[rt].v = (t[rt * 2].v % p + t[rt * 2 + 1].v % p) % p;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> p;//输入
                       //取模
    n %= p;
    m %= p;
    tt a[n];//开数组
    memset(a, 0, sizeof(a));//清空
    for (int i = 1; i <= n; i++)//数组输入
    {
        cin >> a[i];
        a[i] %= p;
    }
    cstree(1, a, 1, n);//建树
    for (int i = 1; i <= m; i++)//执行指令
    {
        int sw = 0;
        cin >> sw;
        if (sw == 1)//乘法指令
        {
            tt x, y, k;
            cin >> x >> y >> k;
            updatemul(1, 1, n, x, y, k);
        }
        if (sw == 2)//加法指令
        {
            tt x, y, k;
            cin >> x >> y >> k;
            updateadd(1, 1, n, x, y, k);
        }
        if (sw == 3) //查询指令
        {
            tt x, y;
            cin >> x >> y;
            cout << sstree(1, 1, n, x, y) % p << endl;
        }
    }
    return 0;
}
