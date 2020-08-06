#include<iostream>
using namespace std;
int First[100001],End[100001]; 
void change(int &a,int &b){
	int text=a;a=b,b=text;
}
void qsort(int l,int r){
	int a=l,b=r,mid=End[(l+r)/2];
	while(a<=b){
		while(End[a]<mid)a++;
		while(End[b]>mid)b--;
		if(a<=b){
			change(End[a],End[b]);
			change(First[a],First[b]);
			a++,b--;
		}
	}
	if(l<b)qsort(l,b);
	if(a<r)qsort(a,r);
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>First[i]>>End[i];
	}
	qsort(1,n);
	int ans=0;
	for(int i=1,text=-1;i<=n;i++){
		if(First[i]>=text)ans++,text=End[i];
	}
	cout<<ans<<endl;
	return 0;
}
/*
11
3 5
1 4
12 14
8 12
0 6
8 11
6 10
5 7
3 8
5 9
2 13

*/
/*
4
*/
