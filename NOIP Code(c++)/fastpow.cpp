#include<iostream>
#define LL long long
using namespace std;
LL fpow(LL a,LL b)
{
	LL base=a,ans=1;
	while(b>0)
	{
		if(b&1) ans*= base;
		base *= base ;
		b=b>>1;
	}
	return ans;
}
int main()
{
	LL a,b;
	cin>>a>>b;
	cout<<fpow(a,b)<<endl;
}

