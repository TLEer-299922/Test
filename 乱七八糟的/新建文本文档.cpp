#include<iostream>
using namespace std;
int x[100001],num,a[100001],b[100001];
int cifang(int a)
{
	int c=0,i,j;num=1;
	x[0]=1;
	for(i=0; i<num; i++) {
		for(j=0; j<num; j++) {
			if(x[j]>=5) {
				x[j]=2*(x[j]-5)+c;
				c=1;
			} else {
				x[j]=2*x[j]+c;
				c=0;
			}
		}
		if(c==1) {
			num++;
			c=0;
			x[j]=1;
		}
	}
	return num;
}
int mod()
{
	int d=0;
	for(int i=0; i<num; i++)  d=(d*10+(x[i]-'0'))%998344353;
	return d;
}
void chu()
{
	for(int i=num; i>=1; i--) {
		a[i]=b[i]/25;
		b[i]%=25;
		a[i-1]+=a[i]*10;
	}
	while(a[num]==0&&num>1)num--;
}
void fz(bool c)
{
	if(c)for(int i=0; i<num; i++) {
		x[i]=a[i]=b[i];
	}
	else for(int i=0; i<num; i++) {
		a[i]=x[i]=b[i];
	}
}
void cheng(int b)
{
	int jinwei = 0;
	for (int i = 0 ; i < num ; i++) {
		a[i] = a[i] * b + jinwei;
		jinwei = a[i] / 10;
		a[i] %= 10;
	}
	if (jinwei != 0) {
		a[num] = jinwei;
		num++;
		while (a[num - 1] >= 10) {
			a[num] = a[num - 1] / 10;
			a[num - 1] %= 10;
			num++;
		}
	}
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<num<<endl;
	cifang(a+2);
	cout<<num<<endl;
	cheng(b);
	cout<<num<<endl;
	fz(1);
	cout<<num<<endl;
	chu();
	cout<<num<<endl;
	fz(0);
	cout<<num<<endl;
	mod();
	for(int i=0;i<num;i++){
		cout<<x[i];
	}
	cout<<endl;
	return 0;
}
