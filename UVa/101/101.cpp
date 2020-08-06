// a url="https://www.luogu.com.cn/problem/UVA101:
#include<iostream>
#include<string>
using namespace std;
string s="0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24";
string a[25]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24"};
void plus(string d,int n){
    if(a[n]!=" ")a[n]+=d;
    else a[n]=d;
}
void move_onto(int a,int b){

}
// move_onto
move_over
pile_over
pile_onto
int main(){
    int n,x,y;cin>>n;
    char c;cin>>c;
    if(c=='m'){
        cin>>c>>c>>c>>x>>c>>c;
        if(c=='n'){
            cin>>c>>c>>y;
            move_onto(x,y);
        }
        else {
            cin<<c<<c<<y;
            move_over(x,y);
        }
    }
    else if(c=='p')print();
    else {
         cin>>c>>c>>c>>x>>c>>c;
        if(c=='n'){
            cin>>c>>c>>y;
            pile_onto(x,y);
        }
        else {
            cin<<c<<c<<y;
            pile_over(x,y);
        }
    }
}
