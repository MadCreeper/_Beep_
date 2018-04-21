#include<bits/stdc++.h>
#define LL unsigned long long
using namespace std;
LL a[100];
int main()
{
	for(LL i=1;i<=18;i++)
	{
		a[i]=1;
		for(LL j=1;j<=i;j++)
			a[i]*=i;
		cout<<a[i]<<",";
	}
}