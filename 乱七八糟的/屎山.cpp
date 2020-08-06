#include<iostream>
using namespace std;
int a[5005];
int c[5005],ans;
int main()
{
    int n,s;
    cin>>n>>s;
    a[1]=1;
    for(int i=1;i<=n;i++)
    {
        int jw=0;
		for(int j=1;j<=5000;j++)
		{
			a[j]=a[j]*i+jw;
			jw=a[j]/10;
			a[j]%=10;
		}
		jw=0;
		for(int i=1;i<=5000;i++)
		{
			c[i]+=a[i]+jw;
			jw=c[i]/10;
			c[i]%=10;
		}
    }
    bool flag=0;
    for(int i=5000;i>=1;i--)
    {
        if(c[i]!=0) flag=1;
        if(flag) cout<<c[i];
    }
    cout<<' ';
    for(int i=5000;i>=1;i--){
    	if(c[i]!=0)flag=1;
    	if(c[i]==s&&flag)ans++;
	}
	cout<<ans<<endl;
}
