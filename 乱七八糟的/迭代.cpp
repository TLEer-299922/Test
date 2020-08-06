#include<iostream>
#include<iomanip>
using namespace std;
double a,b,c,d;
double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}
int main(){
	double xx,x1,x2;int x;
	cin>>a>>b>>c>>d;
	cout<<fixed<<setprecision(2);
	for(x=-100;x<=100;x++){
		x1=x;
		x2=x+1;
		if(f(x1)==0)cout<<x1<<' ';
		else if(f(x1)*f(x2)<0){
			while(x2-x1>=0.001){
				xx=(x1+x2)/2;
				if(f(xx)*f(x1)<=0){
					x2=xx;
				}
				else x1=xx;
			}
			cout<<x1<<' ';
		}
	}
	return 0;
}
