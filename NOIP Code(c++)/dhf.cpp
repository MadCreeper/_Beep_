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
#define tt ll//�߶������ݸ�ʽ
#define ts 100000//�߶�����С
int p, n, m;
struct stree //�ڵ����ݽṹ
{
    tt v;//�ڵ�ֵ
    tt a;//�ڵ�ӷ����
    tt cs;//�ڵ��ӽڵ����
    tt m;//�ڵ�˷����
}t[ts * 4 + 1];
//����
void cstree(tt rt, tt a[], tt st, tt ed)//���ڵ�rt;��������a[];��ǰ����st,ed
{
    t[rt].a = 0;
    t[rt].m = 1;
    if (st == ed)//���ӽڵ�
    {
        t[rt].v = a[st];
        t[rt].cs = 1;
        return;
    }
    tt md = (st + ed) >> 1;//�е�
                           //�ݹ齨��
    cstree(rt * 2, a, st, md);
    cstree(rt * 2 + 1, a, md + 1, ed);
    //�����ӽڵ�������ڵ�
    t[rt].v = (t[rt * 2].v % p) + (t[rt * 2 + 1].v % p) % p;//�ӽڵ�ֵ��
    t[rt].cs = t[rt * 2].cs + t[rt * 2 + 1].cs;//�ӽڵ����
}
//������
inline void pushdown(tt rt)//���ڵ�rt
{
    if (t[rt].m!=1)//���ڳ˷����
    {
        //���ӽڵ��޸�
        //����ֵ
        t[rt * 2].v *= t[rt].m;
        t[rt * 2].v %= p;
        //����ӷ����
        t[rt * 2].a *= t[rt].m;
        t[rt * 2].a %= p;
        //����·�
        t[rt * 2].m *= t[rt].m;
        t[rt * 2].m %= p;
        //���ӽڵ��޸�
        //����ֵ
        t[rt * 2 + 1].v *= t[rt].m;
        t[rt * 2 + 1].v %= p;
        //����ӷ����
        t[rt * 2 + 1].a *= t[rt].m;
        t[rt * 2 + 1].a %= p;
        //����·�
        t[rt * 2 + 1].m *= t[rt].m;
        t[rt * 2 + 1].m %= p;
        //��ձ��
        t[rt].m = 1;
    }
    if (t[rt].a)//���ڼӷ����
    {
        //�ӽڵ��޸�
        //��
        t[rt * 2].v += (t[rt].a%p)*t[rt * 2].cs;
        t[rt * 2].v %= p;
        //��
        t[rt * 2 + 1].v += (t[rt].a%p)*t[rt * 2 + 1].cs;
        t[rt * 2 + 1].v %= p;
        //�·ű��
        //��
        t[rt * 2].a += t[rt].a;
        t[rt * 2].a %= p;
        //��
        t[rt * 2 + 1].a += t[rt].a;
        t[rt * 2 + 1].a %= p;
        //��ձ��
        t[rt].a = 0;
    }
}
//����
tt sstree(tt rt, tt nst, tt ned, tt sst, tt sed)//���ڵ�rt;��������nst,ned;��������sst,sed
{
    if (sst>ned || sed<nst)//������������������޽���
        return 0;
    if (sst <= nst && sed >= ned)//�������������������
        return t[rt].v % p;
    //������������������н���
    pushdown(rt);//������
    tt md = (nst + ned) >> 1;//�е�
    return (sstree(rt * 2, nst, md, sst, sed) % p + sstree(rt * 2 + 1, md + 1, ned, sst, sed) % p) % p;//�ݹ������ӽڵ�
}
//�˷�����
void updatemul(tt rt, tt nst, tt ned, tt ust, tt ued, tt mul)//���ڵ�rt;��������nst,ned;��������ust,ued;������mul
{
    if (ust>ned || ued<nst)//������������������޽���
        return;
    if (ust <= nst && ued >= ned)//�������������������
    {
        //�ӷ����
        t[rt].a *= mul;
        t[rt].a %= p;
        //ֵ
        t[rt].v *= mul;
        t[rt].v %= p;
        //�˷����
        t[rt].m *= mul;
        t[rt].m %= p;
        return;
    }
    //������������������н���
    pushdown(rt);//������
    tt md = (nst + ned) >> 1;//�е�
                             //�ݹ����
    updatemul(rt * 2, nst, md, ust, ued, mul);
    updatemul(rt * 2 + 1, md + 1, ned, ust, ued, mul);

    //���ĵ�ǰֵ
    t[rt].v = (t[rt * 2].v % p + t[rt * 2 + 1].v % p) % p;
}
// �ӷ�����
void updateadd(tt rt, tt nst, tt ned, tt ust, tt ued, tt add)//���ڵ�rt;��������nst,ned;��������ust,ued;������add
{
    if (ust>ned || ued<nst)//������������������޽���
        return;
    if (ust <= nst && ued >= ned)//�������������������
    {
        t[rt].a += (add % p );
        t[rt].a %= p;
        t[rt].v += (add % p) * t[rt].cs;
        t[rt].v %= p;
        return;
    }
    //������������������н���
    pushdown(rt);//������
    tt md = (nst + ned) >> 1;//�е�
    //�ݹ����
    updateadd(rt * 2, nst, md, ust, ued, add);
    updateadd(rt * 2 + 1, md + 1, ned, ust, ued, add);
    //���ĵ�ǰֵ
    t[rt].v = (t[rt * 2].v % p + t[rt * 2 + 1].v % p) % p;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> p;//����
                       //ȡģ
    n %= p;
    m %= p;
    tt a[n];//������
    memset(a, 0, sizeof(a));//���
    for (int i = 1; i <= n; i++)//��������
    {
        cin >> a[i];
        a[i] %= p;
    }
    cstree(1, a, 1, n);//����
    for (int i = 1; i <= m; i++)//ִ��ָ��
    {
        int sw = 0;
        cin >> sw;
        if (sw == 1)//�˷�ָ��
        {
            tt x, y, k;
            cin >> x >> y >> k;
            updatemul(1, 1, n, x, y, k);
        }
        if (sw == 2)//�ӷ�ָ��
        {
            tt x, y, k;
            cin >> x >> y >> k;
            updateadd(1, 1, n, x, y, k);
        }
        if (sw == 3) //��ѯָ��
        {
            tt x, y;
            cin >> x >> y;
            cout << sstree(1, 1, n, x, y) % p << endl;
        }
    }
    return 0;
}
