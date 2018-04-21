#include<bits/stdc++.h>
using namespace std;
int p;
int ans[510],base[510];
int tmp[1010];
void op1() //ans *=base
{
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=500;i++)
		for(int j=1;j<=500;j++)
		{
			tmp[i+j-1]+=ans[i]*base[j];
		}
		for(int i=1;i<=500;i++)
		{
			tmp[i+1]+=tmp[i]/10;
			tmp[i]%=10;
		}
	memcpy(ans,tmp,sizeof(ans));
}
void op2() //base *=base
{
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=500;i++)
		for(int j=1;j<=500;j++)
		{
			tmp[i+j-1]+=base[i]*base[j];
		}
		for(int i=1;i<=500;i++)
		{
			tmp[i+1]+=tmp[i]/10;
			tmp[i]%=10;
		}
	memcpy(base,tmp,sizeof(base));
}
int main()
{
	cin>>p;
	ans[1]=1;
	base[1]=2;
	int digits=(int)(p*log10(2)+1);
	cout<<digits<<endl;
	while(p!=0)
	{
		if(p%2==1) op1();
		op2();
		p=p/2;
	}
	ans[1]-=1;
	for(int i=500;i>=1;i--)
	{
		cout<<ans[i];
		if((i-1)%50==0) cout<<endl;
	}
}