#include<iostream>
#include<windows.h>
using namespace std;
int main(){
    char c[4]={'/','|','\\','-'};
    int i=0,n;
    cin>>n;
    while(i<n){
        cout<<c[i%4];i++;Sleep(1000);cout<<'\b';
    }
    cout<<"Finished."<<endl;
    return 0;
}