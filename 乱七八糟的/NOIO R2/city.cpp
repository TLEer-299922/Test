#include<iostream>
#include<string>
using namespace std;
int a[5];
string s;
int main()
{
	cin>>s;
	for(int i=1; i<=4; i++)
		cin>>a[i];
	for(int i=0; i<s.size(); i++) {
		for(int j=1; j<=4; j++)
			if(a[j]==i) cout<<'\"';
		cout<<s[i];
	}
	for(int i=1; i<=4; i++)
		if(a[i]>s.size()-1) cout<<'\"';
	cout<<endl;
	return 0;
}
