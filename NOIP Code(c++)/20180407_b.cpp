#include<bits/stdc++.h>
using namespace std;
string rev(string s)
{
    string ret="";
    for(int i=s.size()-1;i>=0;i--)
    {
        ret+=s[i];

    }
    return ret;
}
//string trim()
int main()
{
    int T;
    cin>>T;
    string s;
    while(T--)
    {
        cin>>s;
        if(rev(s)==s) puts("Perfect!");
        else
        {
            int c0=0,c1=0;
            int len=s.size();
            for(int i=0;i<len;i++)
            {
                if(s[i]=='0') c0++;
                else c1++;
            }
            if(len%2==0)
            {
                if(c0%2==0 && c1%2==0) puts("OK!");
                else puts("Pbo!");
            }
            else
            {

                puts("OK!");
            }

        }

    }

}
