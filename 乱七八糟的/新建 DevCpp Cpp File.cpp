#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
    while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
int n,L,v;
long long a[200050],s[200050];
inline bool cmp(double a,double b)
{
    return a>b;
}
int main()
{
    n=read(),L=read(),v=read();
    for (int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    int q=read();
    while (q--)
    {
        long long t=read();
        t=t*v-L;
        if (t<0)
            puts("0");
        else if (s[n]>t)
            cout << upper_bound(s+1,s+n+1,t)-s << endl;
        else
            puts("-1");
    }
    return 0;
}