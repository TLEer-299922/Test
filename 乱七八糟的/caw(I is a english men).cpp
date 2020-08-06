#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct hp{
	int num,bs;
}a[100005];
int n,m,p,t,nown,bs,ans;
bool b[100005];
int main(){
	cin>>n>>m;ans=100001;
	p=0,t=1;
	a[t].num=n,a[t].bs=0,b[n]=true;
	while(p<t){
		++p;
		nown=a[p].num,bs=a[p].bs;
		if(nown==m) {cout<<bs<<endl;return 0;}
 		if(nown+1<100001&&!b[nown+1]) b[nown+1]=true,a[++t].num=nown+1,a[t].bs=bs+1;
		if(nown-1>=0&&!b[nown-1]) b[nown-1]=true,a[++t].num=nown-1,a[t].bs=bs+1;
		if(nown*2<100001&&!b[nown*2]) b[nown*2]=true,a[++t].num=nown*2,a[t].bs=bs+1; 
	}
	return 0;
}

