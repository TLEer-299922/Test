#include<iostream>
using namespace std;
struct asdf{
	double num,fs;int bh;char c;
}a[10002];//a[0].num´æ´¢ÏÂÎÄµÄn 
double pj(asdf a[],int n,int z){
	double num=0.0;
	for(int i=1;i<=n;i++)num+=a[i].num;
	num/=(n-1);
	return num*0.4;
} 
void sort(){
	
}
int main(){
	int n,k;
	cin>>n>>k;
	char c;
	for(int i=1;i<=n;i++) {
		cin>>c;cin>>a[i].num;a[0].num++;
	}
	sort();
}
