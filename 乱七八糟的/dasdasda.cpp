#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
double a,b,c,d;
bool cmp(double a,double b)
{
	return a<b;
}
double f(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
double fl(double x)
{
	return 3*a*x*x+2*b*x+c;
}
int main()
{
	cout<<fixed<<setprecision(2); 
	cin>>a>>b>>c>>d;
	double k[5]={9999.99};
	int t=0;
	for(int x=-100;x<=100;x++){
		double x0=x;
		while(f(x0)!=0&&fl(x0)!=0&&f(x0)/fl(x0)!=0)
			x0-=f(x0)/fl(x0);
		bool g=1;
		for(int i=1;i<=t;i++)if(x0==k[i])g=0;
		if(f(x0)==0&&g){
			k[++t]=x0;
		}
	}
	sort(k,k+4,cmp);
	for(int i=0;i<t;i++)cout<<k[i]<<' ';
	cout<<endl;
	return 0;
}
