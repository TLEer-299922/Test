#include<iostream>
#include<map>
#include<cstdio>
struct Union {
    Union(int n, int m) {
        for (int i=-m;i<=n;i++) {
            a[i]=i;
        }
    }
    int find(int n) {
        return a[n]==n?n:a[n]=find(a[n]);
    }
    void merge(int n, int m) {
        a[find(n)]=find(m);
    }
    bool bro(int n, int m) {
        return find(n)==find(m);
    }
    std::map<int, int>a;
};
int main() {
    int n, m, p, q, ansa=1, ansb=1;
    std::cin>>n>>m>>p>>q;
    Union A(n, m);
    int x, y;
    for (int i=1;i<=p+q;i++) {
        std::cin>>x>>y;
        A.merge(x, y);
    }
    for (int i=2;i<=n;i++) {
        if (A.bro(i, 1))ansa++;
    }
    for (int i=-m;i<=-2;i++) {
        if (A.bro(i, -1))ansb++;
    }
    if (ansb<ansa) {
        std::cout<<ansb<<std::endl;
    }
    else {
        std::cout<<ansa<<std::endl;
    }
    return 0;
}