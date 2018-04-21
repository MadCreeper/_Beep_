#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[200];
int main()
{
	int n;
	while(1)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		if(n==0) break;
		for(int i=1;i<=n;i++)
		{
			int t;
			scanf("%d",&t);
			a[t]++;
		}
		for(int i=0;i<=100;i++)
		{
			for(int j=1;j<=a[i];j++)
            {
				printf("%d ",i);

            }

        }
        cout<<endl;
	}
	return 0;
}
