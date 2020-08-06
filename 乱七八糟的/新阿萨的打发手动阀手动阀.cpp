#include<iostream>
#include<iomanip>
using namespace std;
double a,b,c,d;
double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}
int main(){
	cin>>a>>b>>c>>d;
	double x1,x2;int x;
	for(x=-100000;x<=100000;x++){
		x1=(x-0.05)/100,x2=(x+0.05)/100;
		if(f(x1)*f(x2)<0||f(x1)==0)cout<<fixed<<setprecision(2)<<x/100.0<<' ';
	}
} 
