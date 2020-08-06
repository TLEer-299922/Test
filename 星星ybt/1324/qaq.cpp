#include<iostream>
int num[10001], x, y, n, maxy,minx=10001,hasto[10001][10001],hastonum[10001];
int max(){
    int maxx = 1;
    for (int i =0 ; i <= 10000;i++){
        if(num[i]>num[maxx])
            maxx = i;
    }
    return maxx;
}
bool allzero(){
    for (int i = minx; i <= maxy;i++){
        if(num[i])
            return 0;
    }
    return 1;
}
int main(){
    std::cin >> n;
    for (int i = 0; i < n;i++){
        std::cin >> x >> y;
        if(x<minx)
            minx = x;
        if(y>maxy)
            maxy = y;
        for (int j = x; j < y;j++)
            num[j]++,hasto[j][hastonum[j]++] = j;
    }
    while(!allzero()){
        ans++;
        int c = max();
        for()
    }
}