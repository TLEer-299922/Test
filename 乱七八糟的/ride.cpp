#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[100001],b[100001];
	int n,m;
	int i,j,k;
	cin>>n>>m;
	for(i=0;i<n;i++){
        cin>>a[i];
        if(i<m)
            b[i]=a[i];
    }
    sort(b,b+m);
    for(i=m;i<n;i++){
        b[0]+=a[i];
        k=0;
        while(b[k]>b[k+1]&&k<m-1){
            int t=b[k];
            b[k]=b[k+1];
            b[k+1]=t;
            k++;
        }
    }
    int max=0;
    for(j=0;j<m;j++){
        if(b[j]>max)max=b[j];
    }
	cout<<max<<endl;
}
/*
5 3
4 4 1 2 1


4
*/
