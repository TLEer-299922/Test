#include<iostream>
#include<cstdio>
using namespace std;
bool goed[21][21]={{0}};char c[21][21];int ans,n,m;
void go(int x,int y){
	c[x][y]='v';
	if(!goed[x][y]){
		ans++,goed[x][y]=true;
	}
	else return;
	cout<<'('<<x<<','<<y<<')'<<endl;
	if(c[x][y+1]!='#'&&y<n-1)go(x,y+1);
	if(c[x+1][y]!='#'&&x<n-1)go(x+1,y);
	if(c[x][y-1]!='#'&&y>0)go(x,y-1);
	if(c[x-1][y]!='#'&&x>0)go(x-1,y);
}
int main(){
	// freopen("x.in","r",stdin);
	 freopen("x.out","w",stdout);
	int nowx,nowy,test;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>c[i][j];
			if(c[i][j]=='@')nowx=i,nowy=j;
		}
	}
	cin>>test>>test;
	go(nowx,nowy);
	cout<<ans<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<c[i][j];
		}
		cout<<endl;
	}
	return 0;
	// fclose(stdin);
	fclose(stdout);
} 
