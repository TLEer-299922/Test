#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
struct gold{
	int money;
	double heavy,value;
}a[100001];
bool cmp(gold a,gold b){
	return a.value>b.value;
}
int main(){
	int blanket_n,n,k;
	double ans;
	cin>>blanket_n;
	for(int blanket_i=0;blanket_i<blanket_n;blanket_i++)
	{
		cin>>k>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].heavy>>a[i].money;
			a[i].value=a[i].money/a[i].heavy;
		}
		sort(a,a+n,cmp);
		ans=0.0;
		int i;
		for(i=0;i<n&&(k-a[i].heavy)>=0;i++)ans+=a[i].money,k-=a[i].heavy;
		ans+=a[i].value*k;
		cout<<fixed<<setprecision(2)<<ans<<endl;
	} 
	return 0;
}
