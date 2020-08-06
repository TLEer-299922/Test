#include<iostream>
#include<cmath>
#include<cstdio> 
using namespace std;
int s[400][100002],f[100002];
int main(){
	int n,q;
	freopen("running.in","r",stdin);
	freopen("running.out","w",stdout);
	cin>>n>>q;
	int m=sqrt(n);
	f[0]=1;
	for(int i=1;i<=m;i++)
		for(int j=i;j<=n;j++)
			f[j]=(f[j]+f[j-i])%q;
	s[0][0]=1;
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){
			s[i][j]=s[i][j-i];
			if(j>=(m+1))
				s[i][j]=(s[i][j]+s[i-1][j-(m+1)])%q;
		}
	}
	int ans=0;
	for(int j=0;j<=n;j++){
		long long sum=0;
		for(int i=0;i<=m;i++)
			sum=(sum+s[i][n-j])%q;
		ans=(ans+f[j]*sum)%q;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
