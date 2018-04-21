#include<bits/stdc++.h>
using namespace std;
int a[10000+10];
int main()
{
    int T;
    int n;
    cin>>T;

    while(T--)
    {
        scanf("%d",&n);
        int maxn=-(1<<30),ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>maxn)
            {
                ans=i;
                maxn=a[i];
            }
        }
        printf("%d\n",ans);

    }
}
