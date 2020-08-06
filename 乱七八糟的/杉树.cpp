#include<iostream>
#include<cstring>
using namespace std;
char n[50];
int main()
{
	int t,b;
	cin>>t;
	while(t){
		--t;
		cin>>n>>b;
		int len=strlen(n);
		for(int i=1;i<=b;i++){
			for(int j=0;j<len-1;j++){
				if(n[j]>n[j+1]){
					for(int k=j;k<len-1;k++){
						n[k]=n[k+1];
					}
					break;
				}
			}
			len--;
		}
		for(int i=0;i<len;i++){
			cout<<n[i];
		}
		cout<<endl;
	}
}
