#include<stdio.h>
#include<ctype.h>
inline int read(){
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int main(){
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;++i){
		n=read();
		write((n-1)/2);
		printf("\n"); 
	}
	return 0;
}
// 1 2 3 4 5 6 7 8 9 10
