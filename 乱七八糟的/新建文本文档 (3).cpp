/*���غϲ��ֿ��Դ��Ѿ�����������һ�����ʵ�����濪ʼö�٣��Ӻ���ǰö�٣�ֱ���ҵ����һ�����ʵ�һ����ĸ����Ҫ�����ĵ��ʵĵ�һ����ĸ���
�����Ǹ����ʵ���ĸ��λ�ü�¼Ϊk��Ȼ����Ѿ���������Ǹ����ʴ�k��β����ѭ��ö�٣�ͬʱ��Ҫ�����ĵ��ʴ�ͷ��k����ö�٣�����в���ȵ�һ����
ĸ�ͷ���0�����򷵻��Ǹ����ʵĳ��� -��k + 1�� */
#include<iostream>
#include<string>
using namespace std;
string a[21];
void search(string *s,int n,bool* can,int ans){
	for(int i=0;i<n;i++){
		int c=a[i].find_last_of(s[s.size()]);
		if(can[i]==2||c==npos)continue;
		for(int k=c,j=0;k<n&&j<c;k++,j++)if(s[k]!=a[i])continue;
		if(k==n||j==c)
	}
} 
int main()
{
	cin>>n;
	const int N=n;
	for(int i=0; i<=N; i++)cin>>a[i];
	int can[N]={0};
	search(a[N],N,can) ;
	cout<<a[N].length()<<endl;
	return 0;
}
