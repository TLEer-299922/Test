/*求重合部分可以从已经在龙里的最后一个单词的最后面开始枚举（从后向前枚举）直到找到最后一个单词的一个字母和想要接龙的单词的第一个字母相等
，把那个单词的字母的位置记录为k，然后从已经在龙里的那个单词从k到尾进行循环枚举，同时想要接龙的单词从头到k进行枚举，如果有不相等的一个字
母就返回0，否则返回那个单词的长度 -（k + 1） */
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
