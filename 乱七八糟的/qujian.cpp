#include<iostream>
using namespace std;
int a[100001],b[100001],ans;
void change(int &a,int &b){
	int text=a;a=b,b=text;
}
void qsort(int l,int r){
	int i=l,j=r,m=b[(l+r)/2],m2=a[(l+r)/2];
	while(i<=j){
		while(b[i]<m&&((b[i]==m)&&(a[i]<m2)))i++;
		while(b[j]<m&&((b[j]==m)&&(a[j]>m2)))j++;
		if(i<=j){
			change(a[i],a[j]);
			change(b[i],b[j]);
			i++,j--;
		}
	}
	if(l<j)qsort(l,j);
	if(i<r)qsort(i,r);
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	qsort(1,n);
	for(int i=1,x=-1;i<=n;i++){
		if(x>=a[i])continue;
		ans++;x=b[i];
	}
	cout<<ans<<endl;
	return 0;
}
/*
4
3 6
2 4
0 2
4 7

*/
/*
2
*/
