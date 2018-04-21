#include<bits/stdc++.h>
#define LL long long
const int N=(int)1e5+7;

using namespace std;
struct matrix
{
    const static int MATRIX_N = 11;
    LL a[MATRIX_N][MATRIX_N];
    int col,row;
    matrix(){
    	memset(a,0,sizeof(a));
    }

   	matrix(int x,int y)
   	{
   		row=x;
   		col=y;
   		memset(a,0,sizeof(a));
   	}

   	LL* operator [] (int x) const{ 
   		return a[x];
   	}

   	matrix operator + (const matrix &b) const{

   		matrix ans(row,col);
   		for(int i=0;i<this->row;i++)
   		{
   			for(int j=0;j<this->col;j++)
   			{
   				ans[i][j] = a[i][j] + b[i][j];
   			}
   		}
   		return ans;
   	}
   	void operator * (const matrix &b) const{
   		matrix ans(row,b.col);
   		for(int i=0;i<row;i++)
   		{
   			for(int j=0;j<b.col;j++)
   			{
   				for(int k=0;k<b.row;k++)
   				{
   					ans[i][j]+=a[i][k]*b[k][j];
   				}
   			}
   		}
   		return ans;
   	}	

   	void operator += (const matrix &b){

   		*this = *this + b;
   	}

   	pow(matrix A,int x)
   	{
   		matrix ret(row,row);
   		for(int i=0;i<row;i++)
   		{
   			ret[i][i]=1;
   		}
   		matrix tmp = A;
   		
		while(b>0)
		{
			if(b&1) ret=ret * tmp;
			tmp = tmp*tmp; 
			b=b>>1;
		}
		return ret;
   	}

};
bool canPlus(matrix a,matrix b)
{
	if(a.row==b.row && a.col==b.col)
		return true;
	return false;
}

int main(){

	matrix A,B,C;

    return 0;
}
