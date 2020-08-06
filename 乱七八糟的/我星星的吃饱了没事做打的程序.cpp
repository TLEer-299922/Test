/*
In the past Daiyuqi and Huangweian were full so I wrote this app.
*/ 
#include<iostream>
#include<cmath>
#include<cstdio> 
#define ULL unsigned long long
#define n 10000000000000000000ULL
using namespace std;
bool is(ULL a){
	if(a==1)return 0;
	ULL c=ceil(sqrt(a)),i;
	for(i=2;i<c;i++)if(a%i==0)break;
	if(i==c)return 1;return 0;
} 
int main(){
	freopen("ËØÊý.txt","w",stdout);
	for(ULL i=100;i<n;i*=10){
		int pop=100;
		cout<<'<'<<i<<':'<<endl;
		for(ULL j=i;j&&pop>0;j--){
			if(is(j)){
				pop--;cout<<j<<',';
			}
		}
		cout<<endl<<'>'<<i<<':'<<endl;
		pop=100;
		for(ULL j=i;pop>0;j++){
			if(is(j)){
				pop--;cout<<j<<',';
			}
		}
		cout<<endl<<endl;
	}
	fclose(stdout);
}
