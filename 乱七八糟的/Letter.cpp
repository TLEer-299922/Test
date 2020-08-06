#include<iostream>
using namespace std;
bool Letter[26];int x,y,ans=1;char a[21][21];int goes[4040][2]={{0,0}},f;
void dfs(int o,int nowx,int nowy){
	int b=0;
	cout<<'('<<nowx<<','<<nowy<<')'<<"->";
	if(nowx!=0&&!Letter[a[nowx-1][nowy]])b=1,Letter[a[nowx-1][nowy]]=1,dfs(o+1,nowx-1,nowy);
	if(nowx!=x-1&&!Letter[a[nowx+1][nowy]])b=2,Letter[a[nowx+1][nowy]]=1,dfs(o+1,nowx+1,nowy);
	if(nowy!=0&&!Letter[a[nowx][nowy-1]])b=3,Letter[a[nowx][nowy-1]]=1,dfs(o+1,nowx,nowy-1);
	if(nowy!=x-1&&!Letter[a[nowx][nowy+1]])b=4,Letter[a[nowx][nowy+1]]=1,dfs(o+1,nowx,nowy+1);
	if(!b)if(o>ans)ans=o;
}
int main(){
	cin>>x>>y;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cin>>a[i][j];
		}
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
} 
