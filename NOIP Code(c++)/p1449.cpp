#include<bits/stdc++.h>
using namespace std;
string s;
stack<int> m;
int stoi(string st)
{
    int ret=0;
    for(int i=0;i<st.length();i++)
    {
      ret*=10;
      ret+=st[i]-'0';
    }
    //cout<<ret<<endl;
    return ret;
}
int main()
{
        cin>>s;
        int pos=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='.')
            {
                //cout<<s.substr(pos,i-pos)<<endl;
                //cout<<pos<<" "<<i<<endl;
                m.push(stoi(s.substr(pos,i-pos)));
                pos=i+1;
            }
            if(s[i]=='+')
            {
                int a,b;
                b=m.top(); m.pop();
                a=m.top(); m.pop();
                m.push(a+b);
                pos=i+1;
            }
            if(s[i]=='-')
            {
                int a,b;
                b=m.top(); m.pop();
                a=m.top(); m.pop();
                m.push(a-b);
                pos=i+1;
            }
            if(s[i]=='*')
            {
                int a,b;
                b=m.top(); m.pop();
                a=m.top(); m.pop();
                m.push(a*b);
                pos=i+1;
            }
            if(s[i]=='/')
            {
                int a,b;
                b=m.top(); m.pop();
                a=m.top(); m.pop();
                m.push(a/b);
                pos=i+1;
            }
        }
        cout<<m.top()<<endl;
}

