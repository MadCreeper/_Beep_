#include<bits/stdc++.h>
typedef long long int LL;
using namespace std;
LL T,n;
LL gcd(LL a,LL b)
{
    return (b==0)? a: gcd(b,a%b);
}
struct frac
{
    LL fz,fm;
    frac(){fz=0;fm=1;}
    frac(LL x, LL y): fz(x),fm(y){}
    frac operator + (const frac &a)const{
        LL fm2 = fm * a.fm / gcd(a.fm,fm);
        LL fz2 = (fm2/fm)*fz + (fm2/a.fm)*a.fz;
        return frac{fz2,fm2};
    }
    frac operator / (const frac &a)const{
        LL fm2=fm*a.fz, fz2 = fz*a.fm;
        LL g= gcd(fm2,fz2);
        fm2 /= g; fz2/=g;
        return frac{fz2,fm2};
    }

}a[100],b[100];
int main()
{
    cin>>T;
    for(LL k=1;k<=T;k++)
    {
        cin>>n;

        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i].fz);
        for(int i=1;i<=n;i++)
            scanf("%lld",&b[i].fz);

        frac ans=frac(0,1);

        for(int i=n;i>=1;i--)
        {
            ans=b[i]/(a[i]+ans);
        }
        printf("Case #%lld: %lld %lld\n",k,ans.fz,ans.fm);
    }
    return 0;
}
