#include<bits/stdc++.h>
using namespace std;

vector<string> state;
vector<string> mp;
int den[200];
int t[10][10];
void pt(string ss)
{
   for(int i=0;i<ss.length();i++)
   {
   	if(ss[i]!='0')putchar(ss[i]);
   	else putchar('-');
   	if((i+1)%10==0) putchar('\n');
   }
   putchar('\n');
}
string tran()
{
	string ret="";
	for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
           ret+=t[i][j]+'0';

    }
    return ret;
}
void init() //枚举 一架飞机的状态
{
	for(int i=0;i<=6;i++)  //up
    {

        for(int j=2;j<=7;j++)
        {
            memset(t,0,sizeof(t));
            t[i][j]=2;
            t[i+1][j]=t[i+2][j]=t[i+3][j]=1;
            t[i+1][j-1]=t[i+1][j-2]=t[i+1][j+1]=t[i+1][j+2]=1;
            t[i+3][j-1]=t[i+3][j+1]=1;
            string pp=tran();
			//pt(tran());
            state.push_back(pp);
        }
    }

  	for(int i=3;i<=9;i++)  //down
    {

        for(int j=2;j<=7;j++)
        {
            memset(t,0,sizeof(t));
            t[i][j]=2;
            t[i-1][j]=t[i-2][j]=t[i-3][j]=1;
            t[i-1][j-1]=t[i-1][j-2]=t[i-1][j+1]=t[i-1][j+2]=1;
            t[i-3][j-1]=t[i-3][j+1]=1;
            string pp=tran();
			//pt(tran());
            state.push_back(pp);

        }
    } //left
    for(int i=2;i<=7;i++)
    {

        for(int j=0;j<=6;j++)
        {
            memset(t,0,sizeof(t));
            t[i][j]=2;
            t[i][j+1]=t[i][j+2]=t[i][j+3]=1;
            t[i+1][j+1]=t[i+2][j+1]=t[i-1][j+1]=t[i-2][j+1]=1;
            t[i+1][j+3]=t[i-1][j+3]=1;
            string pp=tran();
			//pt(tran());
            state.push_back(pp);

        }
    }
    for(int i=2;i<=7;i++)
    {

        for(int j=3;j<=9;j++)
        {
            memset(t,0,sizeof(t));
            t[i][j]=2;
            t[i][j-1]=t[i][j-2]=t[i][j-3]=1;
            t[i+1][j-1]=t[i+2][j-1]=t[i-1][j-1]=t[i-2][j-1]=1;
            t[i+1][j-3]=t[i-1][j-3]=1;
            string pp=tran();
			//pt(tran());
            state.push_back(pp);

        }
    }
}
void overlie() //将三架飞机叠在一起
{
	int siz=state.size(); //cout<<siz<<endl;
	for(int i=0;i<siz;i++)
		for(int j=i+1;j<siz;j++)
			for(int k=j+1;k<siz;k++)
			{
				//cout<<1<<endl;pt(state[i]);
				//cout<<2<<endl;pt(state[j]);
				//cout<<3<<endl;	pt(state[k]);
				string ss="";
				int cnt = 0;
				bool flag=1;
				for(int p=0;p<10*10;p++)
				{
					ss+=state[i][p]+state[j][p]+state[k][p]-2*'0';

					if(ss[p]=='2') cnt++;
					if(ss[p]>'2' || cnt>3)
					{
						flag=0;
						break;
					}
				}

				if(flag)
				{
					//cout<<mp.size()<<endl;
					//pt(ss);
					mp.push_back(ss);

				}
			}

}
bool found=0;
void eliminate(int x,int y,int val) //删除不符合结果的状态
{
	int pos=(x-1)*10+y-1;
	char c=val+'0';
	int cnt=0;
	for(int i=0;i<mp.size();i++)
	{
		if(mp[i][pos]!=c)
		{
			mp.erase(mp.begin()+i);
			i--;
			cnt++;
		}
	}
	printf("Eliminated %d states , %d left\n",cnt,mp.size());
	if(mp.size()==1) { pt(mp[0]); found=1; return ;}
}
void put_density()
{

    for(int i=0;i<100;i++)
    {
        printf("%7d",den[i]);
        if((i+1)%10==0) cout<<endl;
    }
}
int find_density() //找到最密集的点坐标
{
	int maxd=-1,maxp=0;
	for(int i=0;i<100;i++)
	{
		if(den[i]>maxd && den[i]<mp.size())
		{
			maxp=i;
			maxd=den[i];
		}
	}
	return maxp;
}
void update_density() //更新密度
{
	memset(den,0,sizeof(den));
	for(int k=0;k<mp.size();k++)
		for(int i=0;i<100;i++)
				den[i]+=mp[k][i]-'0';
}

int main()
{
    //freopen("bomb.txt","w",stdout);
	init();

	overlie();
	cout<<"INIT DONE"<<endl;

	update_density();

	int st;
	int step=0;
	char ii;
	int x,y,p;
	while(1)
	{
		cout<<"step:"<<step<<endl;
		put_density();
        step++;
		cout<<"interrupt? y/n"<<endl;

        cin>>ii;
		if(ii=='y') cin>>x>>y;
		else
            {
                p=find_density();
                x=(p/10)+1, y=p%10+1;
            }

		printf("bomb %d %d\n",x,y);
		printf("input result:"); scanf("%d",&st);

		eliminate(x,y,st);
		update_density();
		if(found) break;

	}

}
